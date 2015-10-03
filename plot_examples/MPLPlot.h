#ifndef MPLPLOT_H
#define MPLPLOT_H
#include <Python.h>
#include <string>
#include <map>
#include <vector>

std::string format(const char* fmt, ...)
{
    int size = 512;
    char* buffer = 0;
    buffer = new char[size];
    va_list vl;
    va_start(vl,fmt);
    int nsize = vsnprintf(buffer,size,fmt,vl);
    if(size<=nsize){//fail delete buffer and try again
        delete buffer; buffer = 0;
        buffer = new char[nsize+1];//+1 for /0
        nsize = vsnprintf(buffer,size,fmt,vl);
    }
    std::string ret(buffer);
    va_end(vl);
    delete buffer;
    return ret;
}


std::string vector2string(std::vector<double> x)
{
	std::string s;
	int i = 0;
	for (std::vector<double>::iterator it = x.begin(); it != x.end(); it++)
	{
		if (i != 0) s += ", ";
		s += format("%0.16g",*it);
		i++;
	}
	return s;
}


/*! A C++ equivalent of a dictionary to hold values for the plotting functions
*/
class Dictionary
{
public:
	Dictionary(void){};
	std::map<std::string, std::string> string_values;
	std::map<std::string, double> double_values;

	/// Add a floating point value to the dictionary
	void add(std::string key, double value){
		double_values.insert(std::pair<std::string, double>(key, value));
	};

	/// Add a string to the dictionary
	void add(std::string key, std::string value){
		string_values.insert(std::pair<std::string,std::string>(key,value));
	};

	/// print in the form for the call to plot function in matplotlib.pyplot.plot function
	/// k1 = v1, k2 = v2, k3 = v3 ..... with v3 properly quote escaped
	std::string print_call()
	{
		std::string s;

		int i = 0;
		std::string el;
		for (std::map<std::string, double>::iterator it = double_values.begin(); it != double_values.end(); it ++)
		{
			el += ", " + (*it).first + " = " + format("%0.12g",(*it).second);
			s += el;
			i++;
		}
		el = "";
		for (std::map<std::string, std::string>::iterator it = string_values.begin(); it != string_values.end(); it ++)
		{
			el += ", " + (*it).first + " = '" + (*it).second + "'" ;
			s += el;
			i++;
		}
		
		// Determine what to return (empty if there is nothing here)
		if (i > 0)
		{
			return s;
		}
		else
		{
			return std::string("");
		}
	}

};

/*! A class to contain the information for a call to plot() function
*/
class PlotCallOne
{
private:
	bool dict_set;
public:
	Dictionary dict;
	std::vector<double> y;

	/// Save internal variables for this call to plot function, including the keyword argument function as a Dictionary instance
	PlotCallOne(std::vector<double> data, Dictionary *dict = NULL)
	{
		if (dict != NULL)
		{
			this->dict = *dict;
			dict_set = true;
		}
		else
		{
			dict_set = false;
		}

		this->y = data;
	};
	
	/// return the string for this call, including the preceding import matplotlib.pyplot as plt and the following plt.show()
	std::string tostring()
	{
		std::string s;
		s += "y = [" + vector2string(y) + "]\n";
		{
			s += "plt.plot(y" + dict.print_call()+")\n";	
		}
		return s;
	}
};

/*! A class to contain the information for a call to plot() function
*/
class PlotCall
{
private:
	bool dict_set;
public:
	Dictionary dict;
	std::vector<double> x,y;

	/// Save internal variables for this call to plot function, including the keyword argument function as a Dictionary instance
	PlotCall(std::vector<double> x, std::vector<double> y, Dictionary *dict = NULL)
	{
		if (dict != NULL)
		{
			this->dict = *dict;
			dict_set = true;
		}
		else
		{
			dict_set = false;
		}

		this->x = x;
		this->y = y;
	};
	
	/// return the string for this call, including the preceding import matplotlib.pyplot as plt and the following plt.show()
	std::string tostring()
	{
		std::string s;
		s += "x = [" + vector2string(x) + "]\n";
		s += "y = [" + vector2string(y) + "]\n";
		{
			s += "plt.plot(x, y" + dict.print_call()+")\n";	
		}
		return s;
	}
};

class PyPlotter
{	
private:
	std::vector<PlotCall> PlotCalls;
	std::vector<PlotCallOne> PlotCallsOne;
public:
	void plot(std::vector<double> x, std::vector<double> y, Dictionary *dict = NULL)
	{
		PlotCalls.push_back(PlotCall(x,y,dict));
	};
	void plot_data(std::vector<double> data, Dictionary *dict = NULL)
	{
		PlotCallsOne.push_back(PlotCallOne(data,dict));
	};
	void additional_code(std::string){};

	std::string print_calls()
	{
		std::string s;
		for (std::vector<PlotCall>::iterator it = PlotCalls.begin(); it!=PlotCalls.end(); it++)
		{
			s += (*it).tostring();
		}
		return s;
	}
	
	std::string print_one_calls()
	{
		std::string s;
		for (std::vector<PlotCallOne>::iterator it = PlotCallsOne.begin(); it!=PlotCallsOne.end(); it++)
		{
			s += (*it).tostring();
		}
		return s;
	};
	void init()
	{
		Py_Initialize();
		PyRun_SimpleString("import sys");
		PyRun_SimpleString("print sys.path");
		PyRun_SimpleString("import matplotlib");
		PyRun_SimpleString("matplotlib.use('qt4agg')");
		PyRun_SimpleString("import matplotlib.pyplot as plt");
	}

	void load()
	{
		std::string s = this->print_calls() ;
		PyRun_SimpleString(s.c_str());
	}

	void load_data()
	{
		std::string s = this->print_one_calls() ;
		PyRun_SimpleString(s.c_str());
	}

	void show()
	{
		std::string s = "";
		s += "plt.ylim([-60,20])\n";
		s += "plt.grid(True)\n";
		s += "plt.show()\n";
		PyRun_SimpleString(s.c_str());
	}
		
	void show_all()
	{
		Py_Initialize();
		PyRun_SimpleString("import sys");
		PyRun_SimpleString("print sys.path");
		PyRun_SimpleString("import matplotlib");
		PyRun_SimpleString("matplotlib.use('qt4agg')");
		PyRun_SimpleString("import matplotlib.pyplot as plt");
		std::string s = this->print_calls() ;
		s += "plt.show()\n";
		PyRun_SimpleString(s.c_str());
		//Py_Finalize();
	}

	void show_data()
	{
		Py_Initialize();
		PyRun_SimpleString("import sys");
		PyRun_SimpleString("print sys.path");
		PyRun_SimpleString("import matplotlib");
		PyRun_SimpleString("matplotlib.use('qt4agg')");
		PyRun_SimpleString("import matplotlib.pyplot as plt");
		std::string s = this->print_one_calls() ;
		s += "plt.grid(True)\n";
		s += "plt.show()\n";
		PyRun_SimpleString(s.c_str());
		//Py_Finalize();
	};
};

#endif
