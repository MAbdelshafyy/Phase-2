#ifndef CHEXAGON_H
#define CHEXAGON_H
#include "CFigure.h"

class CHexagon :public CFigure
{

private:

	Point P1;

public:

	CHexagon(Point Center, GfxInfo FigureGfxInfo);
        CHexagon();
	virtual void Draw(Output* pOut) const;
	virtual bool PointIn(Point p);
	virtual void PrintInfo(Output* pOut);
	virtual void Save(ofstream& OutFile);
        virtual void Load(ifstream& InFile);
	virtual void movecrdnts(Point pClicked,Point p2,Point p3);
        
	virtual int ShapeCounter();
};
#endif
