#ifndef SVGFILE_H
#define SVGFILE_H

#include <iostream>
#include <fstream>
#include <set>

const std::string defcol = "black";

class Svgfile
{
    public:
        Svgfile(std::string filename = "output.svg", int _width=1000, int _height=800);
        ~Svgfile();
        void addLine(double x1, double y1, double x2, double y2, std::string color=defcol);
        void addDisk(double x, double y, double r, std::string color=defcol);
        void addFleche(double x1, double y1, double x2, double y2, std::string color);
        void addId(double x, double y, std::string text, std::string color);

        static std::string makeRGB(int r, int g, int b);//couleur separ�e pour degrad�s

        static bool s_verbose;

    private:
        std::string m_filename;
        std::ofstream m_ostrm;
        int m_width;
        int m_height;

        // Pour �viter les ouverture multiples
        static std::set<std::string> s_openfiles;
};

#endif // SVGFILE_H
