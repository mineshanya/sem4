﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;

short const NMAX = 100;   //max cols
short const MMAX = NMAX;  //max rows
short const DEFROWS = 3;  //default rows
short const DEFCOLS = 4;  //default cols
//StringGrid->Cells[col][row]

TForm_main *Form_main;
//---------------------------------------------------------------------------
__fastcall TForm_main::TForm_main(TComponent* Owner)
	: TForm(Owner)
{
	Form_main->Edit_rows->Text=DEFROWS;
	Form_main->Edit_cols->Text=DEFCOLS;
	Form_main->StringGrid->Cells[0][0]="N/N";
}
//---------------------------------------------------------------------------
bool AllColsHaveNegative(){
	int rows = Form_main->Edit_rows->Text.ToInt();
	int cols = Form_main->Edit_cols->Text.ToInt();
	for (short i = 1; i <=cols; i++)
		for (short j = 1; j <=rows; j++)
			if (Form_main->StringGrid->Cells[i][j].ToInt()<0) break;
			else if (j==rows) return false;
return true;
}
int SumOfNegativeNumbers(){
	int sum=0;
	int rows = Form_main->Edit_rows->Text.ToInt();
	int cols = Form_main->Edit_cols->Text.ToInt();
	for (short i = 2; i <=rows; i+=2)
		for (short j = 1; j <=cols; j++)
			if (Form_main->StringGrid->Cells[j][i].ToInt()<0)
				sum+=Form_main->StringGrid->Cells[j][i].ToInt();
return sum;
}
//---------------------------------------------------------------------------
void __fastcall TForm_main::Button_applyClick(TObject *Sender)
{
	if (AllColsHaveNegative()) {
		Form_main->Label_answer->Caption="Sum of negative elements in even rows:";
		Form_main->Label_answer->Visible = true;
		Form_main->Edit_answer->Text = SumOfNegativeNumbers();
		Form_main->Edit_answer->Visible = true;
	}
	else {
		Form_main->Edit_answer->Visible = false;
		Form_main->Label_answer->Caption="Not all columns \ncontains negative numbers";
		Form_main->Label_answer->Visible = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm_main::Form_main_Resize(TObject *Sender)
{
	Form_main->StringGrid->Height = Form_main->Height - (Form_main->GroupBox_Parameters->Top+GroupBox_Parameters->Height+78);
	Form_main->StringGrid->Width = Form_main->Width-32;
}
//---------------------------------------------------------------------------
void __fastcall TForm_main::Edit_rows_change(TObject *Sender)
{
	try {
		int rows = Form_main->Edit_rows->Text.ToInt()+1;
		if (rows>=2 && rows<=MMAX) Form_main->StringGrid->RowCount=rows;
		for (short i = 1; i <=rows; i++)
			Form_main->StringGrid->Cells[0][i]=i;
	} catch (Exception &EConvertError) {}
}
//---------------------------------------------------------------------------
void __fastcall TForm_main::Edit_cols_change(TObject *Sender)
{
	try {
		int cols = Form_main->Edit_cols->Text.ToInt()+1;
		if (cols>=2 && cols<=NMAX) Form_main->StringGrid->ColCount=cols;
		for (short i = 1; i <=cols; i++)
			Form_main->StringGrid->Cells[i][0]=i;
	} catch (Exception &EConvertError) {}
}
//---------------------------------------------------------------------------
void __fastcall TForm_main::Button_rand_matrixClick(TObject *Sender)
{
	try {
	int cols = StrToInt(Form_main->Edit_cols->Text);
	int rows = StrToInt(Form_main->Edit_rows->Text);
	for (short i = 1; i <=rows; i++)
		for (short j = 1; j <=cols; j++)
			Form_main->StringGrid->Cells[j][i]=rand()%101-50;
	} catch (Exception &EConvertError) {}
}
//---------------------------------------------------------------------------
void __fastcall TForm_main::Button_rand_sizeClick(TObject *Sender)
{
	Form_main->Edit_rows->Text=rand()%MMAX+1;
	Form_main->Edit_cols->Text=rand()%NMAX+1;
}
//---------------------------------------------------------------------------
void __fastcall TForm_main::StringGrid_KeyPress(TObject *Sender, System::WideChar &Key)
{
	 if (((Key<'0') || (Key>'9')) && Key!=VK_BACK && Key!='-')
		Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm_main::Button_clearClick(TObject *Sender)
{
	for (short i = 1; i <=MMAX+1; i++)
		for (short j = 1; j <=NMAX+1; j++)
			Form_main->StringGrid->Cells[j][i]="";
	Form_main->Edit_rows->Text=DEFROWS;
	Form_main->Edit_cols->Text=DEFCOLS;
}
//---------------------------------------------------------------------------
void __fastcall TForm_main::MainMenu_Tast_Click(TObject *Sender)
{
MessageDlg("Task is:\nGiven a two-dimensional array.\nFind sum of negative numbers in even rows if every column contains negative number.", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm_main::AboutClick(TObject *Sender)
{
	MessageDlg("This lab created by:\n@Mikhail Trofimovich, A-05-18", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

