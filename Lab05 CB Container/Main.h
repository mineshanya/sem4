//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <fstream>
#include <stdio.h>
//---------------------------------------------------------------------------
class TForm_main : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *SG;
	TMainMenu *MainMenu;
	TMenuItem *Help;
	TMenuItem *Task;
	TGroupBox *GB_Input;
	TLabel *Label_Region;
	TLabel *Label_Center;
	TEdit *Edit_Region;
	TEdit *Edit_Center;
	TButton *Button_Check;
	TButton *Button_Add;
	TButton *Button_Load;
	TGroupBox *GB_Answer;
	TLabel *Label_Answer;
	TButton *Button_ClearList;
	TButton *Button_ClearInput;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall ExitClick(TObject *Sender);
	void __fastcall AboutClick(TObject *Sender);
	void __fastcall TaskClick(TObject *Sender);
	void __fastcall Button_ClearListClick(TObject *Sender);
	void __fastcall Button_AddClick(TObject *Sender);
	void __fastcall Button_ClearInputClick(TObject *Sender);
	void __fastcall Button_CheckClick(TObject *Sender);
	void __fastcall Button_LoadClick(TObject *Sender);
	void __fastcall SG_DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_main(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_main *Form_main;
//---------------------------------------------------------------------------
#endif
