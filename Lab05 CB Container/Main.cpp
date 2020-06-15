﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "ABOUT.h"
#include "Container.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_main *Form_main;
TRegionBook all;
//---------------------------------------------------------------------------
__fastcall TForm_main::TForm_main(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm_main::ExitClick(TObject *Sender) {
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TForm_main::AboutClick(TObject *Sender)
{
	AboutBox->ShowModal();
}

void __fastcall TForm_main::TaskClick(TObject *Sender)
{
ShowMessage("There is a list of regions district centers.\n\
			 Check if given city is a district center of region.");
}
//---------------------------------------------------------------------------


void __fastcall TForm_main::FormCreate(TObject *Sender)
{
	SG->Cells[0][0]=L"№";
	SG->ColWidths[0] = 24;
	SG->Cells[1][0]=L"Region";
	SG->Cells[2][0]="District Center";
}
//---------------------------------------------------------------------------

void __fastcall TForm_main::FormResize(TObject *Sender)
{
	SG->ColWidths[1] = (SG->Width-SG->ColWidths[0]-6)/2;	//Region
	SG->ColWidths[2] = SG->ColWidths[1];					//District center
}
//---------------------------------------------------------------------------

void __fastcall TForm_main::Button_ClearListClick(TObject *Sender)
{
	for (int i = 1; i < SG->RowCount; i++)
		SG->Rows[i]->Clear();
	SG->RowCount=1;
	all.book.clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm_main::Button_AddClick(TObject *Sender)
{
int CurRow = SG->RowCount++;
SG->Cells[0][CurRow] = CurRow;
SG->Cells[1][CurRow] = Edit_Region->Text;
SG->Cells[2][CurRow] = Edit_Center->Text;
all.book.push_back(TRegion(Edit_Region->Text,Edit_Center->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm_main::Button_ClearInputClick(TObject *Sender)
{
	Edit_Region->Text="";
	Edit_Center->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm_main::Button_CheckClick(TObject *Sender)
{
	Label_Answer->Caption = (all.Contain(TRegion(Edit_Region->Text,Edit_Center->Text)))?"Yes":"No";
}
//---------------------------------------------------------------------------


