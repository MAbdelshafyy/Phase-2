#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool PointIn(Point p);
	virtual void PrintInfo(Output* pOut);
	virtual void Save(ofstream& OutFile);
        virtual void Load(Ifstream& InFile);
	virtual int ShapeCounter();
	virtual void movecrdnts(Point pClicked, Point p2, Point p3) ;

};

#endif
