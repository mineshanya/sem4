// ---------------------------------------------------------------------------

#ifndef OutputH
#define OutputH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>

// ---------------------------------------------------------------------------
class TForm_output : public TForm {
__published: // IDE-managed Components
	TLabel *Label_result_title;
	TLabel *Label_result;
	TLabel *Label_add_title;
	TLabel *Label_add;
	TButton *OKButton;
	TStringGrid *StringGrid_add;

	void __fastcall OKButtonClick(TObject *Sender);
	void __fastcall Form_output_Close(TObject *Sender, TCloseAction &Action);

private: // User declarations
public: // User declarations
	__fastcall TForm_output(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm_output *Form_output;
// ---------------------------------------------------------------------------
#endif
