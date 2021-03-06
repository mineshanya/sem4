// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Processing.h"
#include "ABOUT.h"
#include "Parameters.h"
#include "Output.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm_main *Form_main;
int SelRow = 1;
bool cb;

// ---------------------------------------------------------------------------
__fastcall TForm_main::TForm_main(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm_main::Form_main_Create(TObject *Sender) {
	cb = false;
}

// ---------------------------------------------------------------------------
void __fastcall TForm_main::ExitClick(TObject *Sender) {
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TForm_main::ProcessingClick(TObject *Sender) {
	Form_processing = new TForm_processing(this);
	Form_processing->Show();
}

// ---------------------------------------------------------------------------
void __fastcall TForm_main::AboutClick(TObject *Sender) {
	AboutBox = new TAboutBox(this);
	AboutBox->Show();
	About->Enabled = false;
}

// ---------------------------------------------------------------------------
void __fastcall TForm_main::ParametersClick(TObject *Sender) {
	Form_params = new TForm_params(this);
	Form_params->Show();
	Parameters->Enabled = false;
}
// ---------------------------------------------------------------------------

void __fastcall TForm_main::OutputClick(TObject *Sender) {
	if (Form_output) Form_output->Show();
	else ShowMessage("There was no any data to process entered");
}
// ---------------------------------------------------------------------------

// ------------- W I N D O W   V I E W ---------------------------------------
void __fastcall TForm_main::Cascade1Click(TObject *Sender) {
	Cascade();
}

void __fastcall TForm_main::ile1Click(TObject *Sender) {
	Tile();
}

void __fastcall TForm_main::CloseCurrent1Click(TObject *Sender) {
	if (ActiveMDIChild != NULL)
		ActiveMDIChild->Close();
}

void __fastcall TForm_main::CloseAll1Click(TObject *Sender) {
	for (int i = MDIChildCount - 1; i >= 0; i--)
		MDIChildren[i]->Close();
}

void __fastcall TForm_main::MinimizeAll1Click(TObject *Sender) {
	for (int i = MDIChildCount - 1; i >= 0; i--)
		MDIChildren[i]->WindowState = wsMinimized;
}

void __fastcall TForm_main::Next1Click(TObject *Sender) {
	Next();
}

void __fastcall TForm_main::Previuos1Click(TObject *Sender) {
	Previous();
}
// ---------------------------------------------------------------------------
