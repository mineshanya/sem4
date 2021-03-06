program Lab04;

uses
  Vcl.Forms,
  Main in 'Main.pas' {Form2},
  Processing in 'Processing.pas' {Form_processing},
  Parameters in 'Parameters.pas' {Form_params},
  ABOUT in 'ABOUT.pas' {AboutBox},
  Output in 'Output.pas' {Form_output};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TFormMain, FormMain);
  Application.CreateForm(TForm_processing, Form_processing);
  Application.CreateForm(TForm_params, Form_params);
  Application.CreateForm(TAboutBox, AboutBox);
  Application.CreateForm(TForm_output, Form_output);
  Application.Run;
end.
