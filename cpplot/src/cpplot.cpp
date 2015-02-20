/****************************************************************************
Copyright (c) 2011 Jonatan Olofsson All Rites Reversed
License: Gnu Public license (GPL) v3
* Author: Jonatan Olofsson (jonatan.olofsson@gmail.com)
* Version: 0.1
* Based on
Author: Yuichi Katori (yuichi.katori@gmail.com)
Project:MATPLOT++ (MATLAB-like plotting tool in C++).
Version:0.3.13
****************************************************************************/

#include "cpplot.hpp"
#include <algorithm>
#include <cstdio>
#include <thread>
#include <mutex>
#include <iostream>

namespace cpplot {
    figures_t figures;
    figure_t cf;
    typedef std::map<std::string, figure_t> figuremap;
    figuremap named_figures;
    std::mutex figures_mutex;
    std::mutex named_figures_mutex;

    figure_t figure(const std::string name) {
        std::unique_lock<std::mutex> l(named_figures_mutex);
        figure_t f = named_figures[name];
        if(f == nullptr) {
            std::cout << "New figure: " << name << std::endl;
            named_figures[name] = f = figure();
            f->set_window_name(name);
        }
        return f;
    }

    int max_figure_number = 0;
    figure_t figure() {
        return figure(max_figure_number + 1);
    }

    figure_t figure(const int i) {
        if(i > max_figure_number) max_figure_number = i;
        std::unique_lock<std::mutex> l(figures_mutex);
        cf = figures[i];
        if(cf == nullptr) {
            figure_t p(new figure_t_t());
            cf = p;
            glut::register_figure(p);
            figures[i] = p;
            return cf;
        } else {
            return cf;
        }
    }
}
