#include "Paste.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"

Paste::Paste(ApplicationManager* pApp) :Action(pApp) {}

void Paste::ReadActionParameters() {  
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage(" Click at a point to paste the figure");

	pIn->GetPointClicked(pClicked.x, pClicked.y);
}

void Paste::Execute() {
	Output* pOut = pManager->GetOutput();
	CFigure* clipboard = pManager->getClipboard(clipboard);

	if(clipboard==NULL) {
		pOut->PrintMessage("Pasting failed, Clipboard is empty");
	}
	else
	{
		ReadActionParameters();

		if (!(pClicked.y >= UI.ToolBarHeight && pClicked.y < UI.height - UI.StatusBarHeight))//beyshof el point fe range el drawing area wala la
		{
			pOut->PrintMessage("The clicked point is not in the drawing area");
			return;
		}
		//hastakhdem hena el dynamic cast 3ashan aghayar el pointers beta3et el CFigures akhaleeha pointer el paste
			if (dynamic_cast<CSquare*>(clipboard)) { //bey check anhy figure fel clipboard
		Point p2;
		Point p3;
		clipboard->movecrdnts(pClicked, p2, p3);

		CSquare* S = new CSquare(pClicked, p2, clipboard->getGfxInfo()); //bye3mel line gedeed bel crdnts el gedeeda bel dynamic allocation eashan yeb2a "copied"


		pManager->AddFigure(S); //bey add el fig el gedeed lel list

		pOut->PrintMessage("Square is pasted");

	}
	else if (dynamic_cast<CTriangle*>(clipboard)) {
		Point p2;
		Point p3;

		clipboard->movecrdnts(pClicked, p2, p3);

		CTriangle* T = new CTriangle(pClicked, p2, p3, clipboard->getGfxInfo());//same tri bas crdnts gedeeda

		pManager->AddFigure(T);

		pOut->PrintMessage("Triangle is pasted ");
	}
	else if (dynamic_cast<CCircle*>(clipboard)) {
		Point p2;
		Point p3;

		clipboard->movecrdnts(pClicked, p2, p3);

		CCircle* H = new CCircle(pClicked, p2, p3, clipboard->getGfxInfo());//same tri bas crdnts gedeeda

		pManager->AddFigure(H);

		pOut->PrintMessage("Circle is pasted ");
	}
	else  {

		CHexagon* H = new CHexagon(pClicked, p2, p3, clipboard->getGfxInfo());//same tri bas crdnts gedeeda

		pManager->AddFigure(H);

		pOut->PrintMessage("Hexagon is pasted ");
	}
	
}
