object Form_output: TForm_output
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Output'
  ClientHeight = 157
  ClientWidth = 454
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = Form_output_Close
  PixelsPerInch = 96
  TextHeight = 13
  object Label_result_title: TLabel
    Left = 28
    Top = 8
    Width = 41
    Height = 13
    Caption = 'Result:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label_result: TLabel
    Left = 86
    Top = 8
    Width = 112
    Height = 13
    Caption = 'Main output will be here'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label_add_title: TLabel
    Left = 8
    Top = 40
    Width = 61
    Height = 13
    Caption = 'Additional:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label_add: TLabel
    Left = 86
    Top = 40
    Width = 135
    Height = 13
    Caption = 'Additional output will be here'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object OKButton: TButton
    Left = 371
    Top = 124
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 0
    OnClick = OKButtonClick
  end
  object StringGrid_add: TStringGrid
    Left = 8
    Top = 70
    Width = 438
    Height = 48
    ColCount = 20
    DefaultColWidth = 35
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -10
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
end
