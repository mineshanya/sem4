object Form_main: TForm_main
  Left = 0
  Top = 0
  Caption = 'Lab01'
  ClientHeight = 389
  ClientWidth = 597
  Color = clBtnFace
  Constraints.MinHeight = 300
  Constraints.MinWidth = 473
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  OnResize = Form_main_Resize
  DesignSize = (
    597
    389)
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox_Parameters: TGroupBox
    Left = 8
    Top = 8
    Width = 225
    Height = 105
    Caption = 'Parameters'
    TabOrder = 0
    object Label_rows: TLabel
      Left = 24
      Top = 24
      Width = 30
      Height = 13
      Caption = 'Rows:'
    end
    object Label_cols: TLabel
      Left = 8
      Top = 51
      Width = 44
      Height = 13
      Caption = 'Columns:'
    end
    object Edit_rows: TEdit
      Left = 58
      Top = 21
      Width = 48
      Height = 21
      TabOrder = 0
      OnChange = Edit_rows_change
    end
    object Edit_cols: TEdit
      Left = 58
      Top = 48
      Width = 48
      Height = 21
      TabOrder = 1
      OnChange = Edit_cols_change
    end
    object Button_rand_matrix: TButton
      Left = 112
      Top = 46
      Width = 103
      Height = 25
      Caption = 'Randomize matrix'
      TabOrder = 2
      OnClick = Button_rand_matrixClick
    end
    object Button_rand_size: TButton
      Left = 112
      Top = 17
      Width = 103
      Height = 25
      Caption = 'Randomize size'
      TabOrder = 3
      OnClick = Button_rand_sizeClick
    end
    object Button_clear: TButton
      Left = 112
      Top = 75
      Width = 103
      Height = 25
      Caption = 'Clear'
      TabOrder = 4
      OnClick = Button_clearClick
    end
  end
  object GroupBox_Result: TGroupBox
    Left = 239
    Top = 8
    Width = 210
    Height = 105
    Caption = 'Result'
    TabOrder = 1
    object Label_answer: TLabel
      Left = 9
      Top = 50
      Width = 70
      Height = 13
      Caption = 'Label_answer:'
      Visible = False
    end
    object Button_apply: TButton
      Left = 9
      Top = 19
      Width = 192
      Height = 25
      Caption = 'Apply Task'
      TabOrder = 0
      OnClick = Button_applyClick
    end
    object Edit_answer: TEdit
      Left = 9
      Top = 69
      Width = 192
      Height = 21
      Enabled = False
      ReadOnly = True
      TabOrder = 1
      Visible = False
    end
  end
  object StringGrid: TStringGrid
    Left = 8
    Top = 124
    Width = 518
    Height = 216
    Margins.Left = 8
    Margins.Top = 8
    Margins.Right = 8
    Margins.Bottom = 8
    Anchors = [akLeft, akTop, akRight, akBottom]
    ColCount = 3
    RowCount = 3
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 2
    OnKeyPress = StringGrid_KeyPress
  end
  object MainMenu: TMainMenu
    Left = 528
    Top = 8
    object Task: TMenuItem
      Caption = 'Task'
      OnClick = MainMenu_Tast_Click
    end
    object About: TMenuItem
      Caption = 'About'
      OnClick = AboutClick
    end
  end
end
