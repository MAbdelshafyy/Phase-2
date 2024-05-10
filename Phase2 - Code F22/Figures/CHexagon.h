#ifndef CHEXAGON_H
#define CHEXAGON_H
#include "CFigure.h"

class CHexagon :public CFigure
{

private:

	Point P1;

public:

	CHexagon(Point Center, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool PointIn(Point p);
	virtual void PrintInfo(Output* pOut);
	virtual void Save(ofstream& OutFile);

	virtual int ShapeCounter();
};
#endif