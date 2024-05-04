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

};
#endif