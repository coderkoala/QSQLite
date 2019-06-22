object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 320
  ClientWidth = 774
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 8
    Top = 16
    Width = 758
    Height = 218
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object Retrieve: TButton
    Left = 320
    Top = 240
    Width = 75
    Height = 25
    Caption = 'Retrieve'
    TabOrder = 1
    OnClick = RetrieveClick
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    VendorLib = 'C:\libmysql.dll'
    Left = 64
    Top = 16
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'Database=laravel'
      'User_Name=root'
      'Server=127.0.0.1'
      'DriverID=MySQL')
    Connected = True
    Left = 64
    Top = 8
  end
  object FDQuery1: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'use laravel;'
      'select id, name, lname, dob, addr, phone from api_dbs;')
    Left = 192
    Top = 32
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 248
    Top = 32
  end
end
