// ---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#pragma hdrstop

#include "Processing.h"
#include "Parameters.h"
#include "Output.h"
using namespace std;
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TForm_processing *Form_processing;
int Row = 0;
vector<int> arr;

// ---------------------------------------------------------------------------
__fastcall TForm_processing::TForm_processing(TComponent* Owner) : TForm(Owner)
{
}
// ---------------------------------------------------------------------------

void __fastcall TForm_processing::FormCreate(TObject *Sender)
{
	Form_processing->TextProg->Caption = "Find amount and index of first negative element in selected row";
	SG1->ColCount = 5;
	for (int i = 1; i < SG1->ColCount; i++)
		SG1->Cells[i][0] = i;
	SG1->RowCount = 4;
	for (int i = 1; i < SG1->RowCount; i++)
		SG1->Cells[0][i] = i;
}
// ---------------------------------------------------------------------------

void __fastcall TForm_processing::Button_applyClick(TObject *Sender)
{
	Row = CSelectedRowEdit->Value;
	for (int j = 1; j < SG1->ColCount; j++) {
		for (int i = 1; i < SG1->RowCount; i++) {
			if (SG1->Cells[j][i] == "" || SG1->Cells[j][i] == "-")
				SG1->Cells[j][i] = 0;
		}
	}

	int k;
	for (k = 1; k < SG1->ColCount; k++) {
		if(SG1->Cells[k][Row]<0) break;
	}

	Form_output->Show();
	if (k<SG1->ColCount && Row<SG1->RowCount) {
		Form_output->Label_result->Caption="First negative element in "+IntToStr(Row)+" row is "+SG1->Cells[k][Row]+" with index "+IntToStr(k);
	} else {
		Form_output->Label_result->Caption="There are no negative elements in selected row";
    }

	if (Form_params->CB1->Checked)
	{
		arr.clear();
		for (int i = 1; i < SG1->RowCount; i++) {
			for (int j = 1; j < SG1->ColCount; j++) {
				if (StrToInt(SG1->Cells[j][i]) > 0) {arr.push_back(StrToInt(SG1->Cells[j][i])); break;}
			}
		}
		if (!arr.empty()) {
			Form_output->Label_add->Caption = "Array from first positive element in each row is:\n";
			for (int i= 0; i < arr.size(); i++)
				Form_output->Label_add->Caption=Form_output->Label_add->Caption+IntToStr(arr[i])+" ";
			if (arr.size()<(SG1->RowCount-1))
				Form_output->Label_add->Caption=Form_output->Label_add->Caption+"\nNot all rows contains positive elements.";
		}
		else Form_output->Label_add->Caption = "There are no positive elements";
		Form_output->Label_add->Visible = true;
		Form_output->Label_add_title->Visible = true;
	}
	else
	{
		Form_output->Label_add_title->Visible = false;
		Form_output->Label_add->Visible = false;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm_processing::SG1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if (!(Key >= '0' && Key <= '9') && (Key != '-') && (Key != VK_BACK))
		Key = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TForm_processing::CRowEditChange(TObject *Sender)
{
	int n = CRowEdit->Value;
	SG1->RowCount = n + 1;
	for (int i = 1; i < SG1->RowCount; i++)
		SG1->Cells[0][i] = i;
}
//---------------------------------------------------------------------------

void __fastcall TForm_processing::CColEditChange(TObject *Sender)
{
	int n = CColEdit->Value;
	SG1->ColCount = n + 1;
	for (int i = 1; i < SG1->ColCount; i++)
		SG1->Cells[i][0] = i;
}
//---------------------------------------------------------------------------

void __fastcall TForm_processing::Form_processing_Resize(TObject *Sender)
{
SG1->Width= Form_processing->Width-33;
SG1->Height = Form_processing->Height-150;
}
//---------------------------------------------------------------------------

void __fastcall TForm_processing::Button_fillrandClick(TObject *Sender)
{
	for (int j = 1; j < SG1->ColCount; j++)
		for (int i = 1; i < SG1->RowCount; i++)
				SG1->Cells[j][i] = rand()%101-50;
}
//---------------------------------------------------------------------------

