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
		if (dynamic_cast<CLine*>(clipboard)) { //bey check anhy figure fel clipboard
			Point p2;
			Point p3;
			clipboard->movecrdnts(pClicked, p2, p3);

			CLine* L = new CLine(pClicked, p2, clipboard->getGfxInfo ()); //bye3mel line gedeed bel crdnts el gedeeda bel dynamic allocation eashan yeb2a "copied"

			
			pManager->AddFigure(L); //bey add el fig el gedeed lel list

			pOut->PrintMessage("Line is pasted");

		}
		else if (dynamic_cast<CTriangle*>(clipboard)) {
			Point p2;
			Point p3;

			clipboard->shftcrdnts(pClicked, p2, p3);

			CTriangle* T = new CTriangle(pClicked, p2, p3, clipboard->getGfxInfo());//same tri bas crdnts gedeeda

			pManager->AddFigure(T);

			pOut->PrintMessage("Triangle is pasted ");
		}
		else if (dynamic_cast<CRectangle*>(clipboard)) { //beykarar el process de le kol el figs
			Point p2;
			Point p3;

			clipboard->shftcrdnts(pClicked, p2, p3);
			
			CRectangle* R = new CRectangle(pClicked, p2, clipboard->getGfxInfo()); //same rect bas crdnts gedeeda

			pManager->AddFigure(R);

			pOut->PrintMessage("Rectangle is pasted");
		}
		
		else {
			CCircle* C = new CCircle(pClicked, clipboard->getGfxInfo());  //same circ bas crdnts gedeeda

			pManager->AddFigure(C);
			pOut->PrintMessage("Circle is pasted");
		}
	}
	
}
