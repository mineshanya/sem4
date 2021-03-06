// ---------------------------------------------------------------------------

#ifndef MainH
#define MainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>

// ---------------------------------------------------------------------------
class TForm_main : public TForm {
__published: // IDE-managed Components
	TMainMenu *MainMenu;
	TMenuItem *File;
	TMenuItem *Exit;
	TMenuItem *Task;
	TMenuItem *Parameters;
	TMenuItem *Processing;
	TMenuItem *Help;
	TMenuItem *About;
	TMenuItem *Output;
	TMenuItem *Windows1;
	TMenuItem *Cascade1;
	TMenuItem *ile1;
	TMenuItem *CloseCurrent1;
	TMenuItem *CloseAll1;
	TMenuItem *MinimizeAll1;
	TMenuItem *Next1;
	TMenuItem *Previuos1;

	void __fastcall ExitClick(TObject *Sender);
	void __fastcall ProcessingClick(TObject *Sender);
	void __fastcall AboutClick(TObject *Sender);
	void __fastcall ParametersClick(TObject *Sender);
	void __fastcall OutputClick(TObject *Sender);
	void __fastcall Cascade1Click(TObject *Sender);
	void __fastcall ile1Click(TObject *Sender);
	void __fastcall Form_main_Create(TObject *Sender);
	void __fastcall CloseCurrent1Click(TObject *Sender);
	void __fastcall CloseAll1Click(TObject *Sender);
	void __fastcall MinimizeAll1Click(TObject *Sender);
	void __fastcall Next1Click(TObject *Sender);
	void __fastcall Previuos1Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm_main(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm_main *Form_main;
// ---------------------------------------------------------------------------
#endif
