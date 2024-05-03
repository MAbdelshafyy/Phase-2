#include "Output.h"
#include "Input.h"
#include <cmath>


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.LineUnderTBWidth = 2;
	UI.MenuItemWidth = 69;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project - Spring 2024");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	//marwan
	MenuItemImages[ITM_SQR] = "images\\MenuItems\\Menu_Sqr.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hex.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_SLCT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_BRDR] = "images\\MenuItems\\Menu_border.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Menu_fill.jpg";
	MenuItemImages[ITM_DLT] = "images\\MenuItems\\Menu_delete.jpg";
	MenuItemImages[ITM_DLTALL] = "images\\MenuItems\\Menu_deleteall.jpg";
	MenuItemImages[ITM_CPY] = "images\\MenuItems\\Menu_copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_cut.jpg";
	MenuItemImages[ITM_PST] = "images\\MenuItems\\Menu_paste.jpg";
	MenuItemImages[ITM_BTOF] = "images\\MenuItems\\Menu_fronttoback.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_load.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Menu_play.jpg";
	//
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list  

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	//marwan
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	string PlayMenuItemImages[PLAY_ITM_COUNT];
	PlayMenuItemImages[ITM_PCKCLR] = "images\\MenuItems\\Menu_PickColor.jpg";
	PlayMenuItemImages[ITM_PCKSHP] = "images\\MenuItems\\Menu_PickShape.jpg";
	PlayMenuItemImages[ITM_PCKBTH] = "images\\MenuItems\\Menu_PickBoth.jpg";
	PlayMenuItemImages[ITM_DRAW] = "images\\MenuItems\\Menu_Draw.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayMenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}

void Output::DrawSquare(Point P1, GfxInfo SquareGfxInfo, bool selected) const
{
	// Determine drawing color
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	// Figure should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	// Set drawing style
	drawstyle style;
	if (SquareGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else {
		style = FRAME;
	}

	// Calculate side length of the square
	const int s = 200;

	int arrx[4] = { P1.x + s / 2, P1.x + s / 2, P1.x - s / 2, P1.x - s / 2 }; // top right, bottom right, bottom left, top left
	int arry[4] = { P1.y + s / 2, P1.y - s / 2, P1.y - s / 2, P1.y + s / 2 }; // top right, bottom right, bottom left, top left

	pWind->SetPen(DrawingClr, 1);
	pWind->DrawPolygon(arrx, arry, 4, style);
}
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected) {
		DrawingClr = UI.HighlightColor;
	}//Figure should be drawn highlighted
	else {
		DrawingClr = TriangleGfxInfo.DrawClr;  //when not clicked it is not highlighted
	}
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriangleGfxInfo.isFilled) {

		style = FILLED;

	}
	else {
		style = FRAME;
	}
	const int iX1 = P1.x;
	const int iX2 = P2.x;
	const int iX3 = P3.x;
	const int iY1 = P1.y;
	const int iY2 = P2.y;
	const int iY3 = P2.y;
	pWind->DrawTriangle(iX1, iY1, iX2, iY2, iX3, iY3, style);
}

void Output::DrawHexagon(Point P1, GfxInfo HexagonGfxInfo, bool selected) const
{
	// Determine drawing color
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	// Figure should be drawn highlighted
	else
		DrawingClr = HexagonGfxInfo.DrawClr;

	// Set drawing style
	drawstyle style;
	if (HexagonGfxInfo.isFilled)
		style = FILLED;
	else
		style = FRAME;

	// Calculate side length of the hexagon
	const int s = 100;

	int arrx[6] = { P1.x - s, P1.x - (s/2), P1.x + s / 2, P1.x + s , P1.x + s / 2, P1.x - s / 2 }; // right, left, upright, upleft, downright, downleft
	int arry[6] = { P1.y, P1.y - (sqrt(3)*(s/2)), P1.y - (sqrt(3) / 2) * s, P1.y, P1.y + (sqrt(3) / 2) * s, P1.y +(sqrt(3) / 2) * s};

	pWind->SetPen(DrawingClr, 1);
	pWind->SetBrush(HexagonGfxInfo.FillClr); // Set brush regardless of style for consistency
	pWind->DrawPolygon(arrx, arry, 6, style);
}
void Output::DrawCirc(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected) const
{
	int r = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y)) / 2;
	int iX = (P1.x + P2.x) / 2;
	int iY = (P1.y + P2.y) / 2;
	color DrawingClr;
	if (selected) {
		DrawingClr = UI.HighlightColor;
	}//Figure should be drawn highlighted
	else {
		DrawingClr = CircleGfxInfo.DrawClr;  //when not clicked it is not highlighted
	}
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircleGfxInfo.isFilled)

		style = FILLED;


	else
		style = FRAME;

	pWind->DrawCircle(iX, iY, r, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}