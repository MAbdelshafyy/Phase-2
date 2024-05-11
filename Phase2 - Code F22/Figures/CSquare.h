#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center1;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
        CSquare();
	virtual void Draw(Output* pOut) const;
	virtual void movecrdnts(Point pClicked, Point p2, Point p3) ;
    virtual void Save(ofstream& OutFile);
    virtual void Load(ifstream& InFile);
    virtual void PrintInfo(Output* pOut);
};

#endif
