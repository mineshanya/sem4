object Form_main: TForm_main
  Left = 0
  Top = 0
  Caption = 'Lab05'
  ClientHeight = 393
  ClientWidth = 392
  Color = clBtnFace
  Constraints.MinHeight = 370
  Constraints.MinWidth = 400
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  OnCreate = FormCreate
  OnResize = FormResize
  DesignSize = (
    392
    393)
  PixelsPerInch = 96
  TextHeight = 13
  object SG: TStringGrid
    Left = 8
    Top = 8
    Width = 221
    Height = 377
    Anchors = [akLeft, akTop, akRight, akBottom]
    ColCount = 3
    DefaultRowHeight = 18
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 0
    OnDblClick = SG_DblClick
  end
  object GB_Input: TGroupBox
    Left = 235
    Top = 8
    Width = 148
    Height = 241
    Anchors = [akTop, akRight]
    Caption = 'Input Data'
    TabOrder = 1
    object Label_Region: TLabel
      Left = 12
      Top = 16
      Width = 33
      Height = 13
      Caption = 'Region'
    end
    object Label_Center: TLabel
      Left = 12
      Top = 62
      Width = 67
      Height = 13
      Caption = 'District center'
    end
    object Edit_Region: TEdit
      Left = 12
      Top = 35
      Width = 125
      Height = 21
      TabOrder = 0
    end
    object Edit_Center: TEdit
      Left = 12
      Top = 81
      Width = 125
      Height = 21
      TabOrder = 1
    end
    object Button_Check: TButton
      Left = 12
      Top = 139
      Width = 125
      Height = 25
      Caption = 'Check'
      TabOrder = 2
      OnClick = Button_CheckClick
    end
    object Button_Add: TButton
      Left = 12
      Top = 108
      Width = 125
      Height = 25
      Caption = 'Add'
      TabOrder = 3
      OnClick = Button_AddClick
    end
    object Button_Load: TButton
      Left = 12
      Top = 170
      Width = 125
      Height = 25
      Caption = 'Load Some Data'
      TabOrder = 4
      OnClick = Button_LoadClick
    end
    object Button_ClearList: TButton
      Left = 74
      Top = 201
      Width = 63
      Height = 25
      Caption = 'Clear list'
      TabOrder = 5
      OnClick = Button_ClearListClick
    end
    object Button_ClearInput: TButton
      Left = 12
      Top = 201
      Width = 63
      Height = 25
      Caption = 'Clear Input'
      TabOrder = 6
      OnClick = Button_ClearInputClick
    end
  end
  object GB_Answer: TGroupBox
    Left = 235
    Top = 255
    Width = 148
    Height = 130
    Anchors = [akTop, akRight, akBottom]
    Caption = 'Answer'
    Constraints.MinHeight = 60
    TabOrder = 2
    object Label_Answer: TLabel
      Left = 12
      Top = 16
      Width = 93
      Height = 13
      Caption = 'Answer will be here'
    end
  end
  object MainMenu: TMainMenu
    Left = 72
    Top = 240
    object File1: TMenuItem
      Caption = 'File'
      object Exit: TMenuItem
        Caption = 'Exit'
        OnClick = ExitClick
      end
    end
    object Help: TMenuItem
      Caption = 'Help'
      object About: TMenuItem
        Caption = 'About'
        OnClick = AboutClick
      end
      object Task: TMenuItem
        Caption = 'Task'
        OnClick = TaskClick
      end
    end
  end
end
