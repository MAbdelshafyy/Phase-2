#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphics info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	double getTriangleArea(Point A, Point B, Point C);

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure

	void DeleteFigure(CFigure* pFig);

	int GetID();
	void SetID(int id);

	string GetColorType(color type) const;  //Change from color to string
        color getColorObj(string) const; //Change from string to color

	color GetDrawClr();
	color GetFillClr();
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure
	virtual bool PointIn(Point p) = 0;
	///Decide the parameters that you should pass to each function	

virtual void movecrdnts(Point pClicked, Point p2, Point p3) = 0;

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &InFile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif
