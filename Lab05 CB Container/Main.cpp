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

void ClearList(){
	for (int i = 1; i < Form_main->SG->RowCount; i++)
			Form_main->SG->Rows[i]->Clear();
		Form_main->SG->RowCount=1;
		all.book.clear();
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
	SG->Cells[0][0]=UnicodeString("№");
	SG->ColWidths[0] = 24;
	SG->Cells[1][0]="Region";
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
	ClearList();
}
//---------------------------------------------------------------------------

void __fastcall TForm_main::Button_AddClick(TObject *Sender)
{
	if (Edit_Region->Text!="" && Edit_Center->Text!="") {
		if  (!all.Contain(TRegion(Edit_Region->Text,Edit_Center->Text))) {
			int CurRow = SG->RowCount++;
			SG->Cells[0][CurRow] = CurRow;
			SG->Cells[1][CurRow] = Edit_Region->Text;
			SG->Cells[2][CurRow] = Edit_Center->Text;
			all.book.push_back(TRegion(Edit_Region->Text,Edit_Center->Text));
		}
	}
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
	if (Edit_Region->Text=="" || Edit_Center->Text=="")
		Label_Answer->Caption = "Some fields are empty.\nPlease, fill both fields first!";
	else if (all.Contain(TRegion(Edit_Region->Text,Edit_Center->Text)))
		Label_Answer->Caption = "Yes, list contains\nentered data";
	else Label_Answer->Caption = "No, list doesn't contains\nentered data";
}
//---------------------------------------------------------------------------



void __fastcall TForm_main::Button_LoadClick(TObject *Sender)
{
	ifstream file;
	string region,center;
	int i=1;

	ClearList();

	file.open("Data.txt");
	if (file.is_open()) {
		while (!file.eof()) {
            getline(file,region);
			getline(file,center);
			all.book.push_back(TRegion(region,center));
		}
		file.close();
	} else ShowMessage("Error opening 'Data.txt'");

	SG->RowCount=all.book.size()+1;
	for (list <TRegion>::iterator it = all.book.begin(); it != all.book.end(); ++it) {
		SG->Cells[0][i]=i;
		SG->Cells[1][i]=(*it).region;
		SG->Cells[2][i]=(*it).center;
		i++;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_main::SG_DblClick(TObject *Sender)
{
	if (SG->Row) {
		Edit_Region->Text = SG->Cells[1][SG->Row];
		Edit_Center->Text = SG->Cells[2][SG->Row];
	}
}
//---------------------------------------------------------------------------

