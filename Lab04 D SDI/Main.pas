unit Main;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.Menus, About, Parameters, Processing;

type
  TFormMain = class(TForm)
    MainMenu: TMainMenu;
    File1: TMenuItem;
    Exit: TMenuItem;
    Task: TMenuItem;
    Parameters: TMenuItem;
    Processing: TMenuItem;
    Help: TMenuItem;
    About: TMenuItem;
    procedure ExitClick(Sender: TObject);
    procedure AboutClick(Sender: TObject);
    procedure ProcessingClick(Sender: TObject);
    procedure ParametersClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  FormMain: TFormMain;
  l:boolean;

implementation

{$R *.dfm}

procedure TFormMain.AboutClick(Sender: TObject);
begin
  AboutBox.ShowModal;
end;

procedure TFormMain.ParametersClick(Sender: TObject);
begin
  Form_params:=TForm_params.Create(Self);
  Form_params.CB1.Checked:=l;
  FormMain.Parameters.enabled:=false;
  Form_params.Show;
end;

procedure TFormMain.ExitClick(Sender: TObject);
begin
  Close;
end;

procedure TFormMain.ProcessingClick(Sender: TObject);
begin
  Form_processing:=TForm_processing.Create(self);
  FormMain.Processing.enabled:=false;
  Form_processing.Show;
end;

end.
