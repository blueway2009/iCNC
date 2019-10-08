#pragma once

#include <string.h>
#include < vcclr.h >
#include <windows.h>
#include <iostream>
#include <fstream>

#include ".\CNC\INC\cnc.h"
#include <math.h>


#include ".\DEF\switch.h"
#include ".\DRV\INC\stepMotorDRV.h"

#define pi 3.14159265358979323846
#define length1 75.0
#define length2 75.0
#define cyclingTime 0.02




enum SeriesChartType;

CNC_DATA   cncData;
CNC_DATA   *cncDataPtr = &cncData;

//**********************************************
// Real timer function
//**********************************************
#if HD_TIMER
void _stdcall Timer_ISR_Function(LIOINT *pstINTSource)
{
	cncRTCtl(cncDataPtr);
}
#endif

namespace iCNC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::Label^  labelNZ;
	private: System::Windows::Forms::Label^  labelNY;
	private: System::Windows::Forms::Label^  labelNX;
	private: System::Windows::Forms::Label^  labelINZ;
	private: System::Windows::Forms::Label^  labelINY;
	private: System::Windows::Forms::Label^  labelINX;
	private: System::Windows::Forms::Label^  labelERR;
	private: System::Windows::Forms::Label^  labelM30;
	private: System::Windows::Forms::Label^  labelPZ;
	private: System::Windows::Forms::Label^  labelPY;
	private: System::Windows::Forms::Label^  labelPX;
	private: System::Windows::Forms::Label^  labelHZ;
	private: System::Windows::Forms::Label^  labelHY;
	private: System::Windows::Forms::Label^  labelHX;
	private: System::Windows::Forms::Label^  labelPGM;
	private: System::Windows::Forms::Label^  labelM00;
	private: System::Windows::Forms::Label^  X;
	private: System::Windows::Forms::Label^  Y;
	private: System::Windows::Forms::Label^  Z;
	private: System::Windows::Forms::Label^  labelW;
	private: System::Windows::Forms::Label^  labelV;

	private: System::Windows::Forms::Label^  labelU;
	private: System::Windows::Forms::Label^  W;
	private: System::Windows::Forms::Label^  V;
	private: System::Windows::Forms::Label^  U;
	private: System::Windows::Forms::RichTextBox^  richTextBoxNC;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Label^  labelYear;
	private: System::Windows::Forms::Label^  labelHour;
	private: System::Windows::Forms::Button^  buttonOpen;
	private: System::Windows::Forms::RichTextBox^  richTextBoxFilePath;

	private: System::Windows::Forms::Label^  labelZ;
	private: System::Windows::Forms::Label^  labelY;
	private: System::Windows::Forms::Label^  labelX;
	private: System::Windows::Forms::Button^  buttonXPlus;
	private: System::Windows::Forms::Button^  buttonXMinus;
	private: System::Windows::Forms::Button^  buttonUVW;
	private: System::Windows::Forms::Button^  buttonYPlus;
	private: System::Windows::Forms::Button^  buttonYMinus;
	private: System::Windows::Forms::Button^  buttonZMinus;
	private: System::Windows::Forms::Button^  buttonZPlus;
	private: System::Windows::Forms::Button^  buttonX1;
	private: System::Windows::Forms::Button^  buttonX10;
	private: System::Windows::Forms::Button^  buttonX100;
	private: System::Windows::Forms::Button^  buttonTeachEnd;
	private: System::Windows::Forms::Button^  buttonRecord;
	private: System::Windows::Forms::Button^  buttonTeachStart;
	private: System::Windows::Forms::Button^  buttonSB;
	private: System::Windows::Forms::Button^  buttonFH;
	private: System::Windows::Forms::Button^  buttonM01;
	private: System::Windows::Forms::Button^  buttonReset;

	private: System::Windows::Forms::Button^  buttonStart;

	private: System::Windows::Forms::Button^  buttonMDI;

	private: System::Windows::Forms::Button^  buttonMEM;
	private: System::Windows::Forms::Button^  buttonWHEEL;


	private: System::Windows::Forms::Button^  buttonJOG;


	private: System::Windows::Forms::Button^  buttonTEACH;

	private: System::Windows::Forms::Button^  buttonParameter;
	private: System::Windows::Forms::Button^  buttonAnalog;
	private: System::Windows::Forms::Button^  buttonDiagnosis;


	private: System::Windows::Forms::Button^  buttonEmergencyStop;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Timer^  timerReal;
	private: System::Windows::Forms::Timer^  timerNonreal;




	private: System::Windows::Forms::TrackBar^  trackBar;
	private: System::Windows::Forms::Label^  labelFeedOverride;
	private: System::Windows::Forms::Button^  buttonHOME;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
private: System::Windows::Forms::Label^  labelUPulse;
private: System::Windows::Forms::Label^  labelVPulse;
private: System::Windows::Forms::Label^  labelWPulse;
private: System::Windows::Forms::Button^  buttonClear;








	private: System::ComponentModel::IContainer^  components;

	private:

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelNZ = (gcnew System::Windows::Forms::Label());
			this->labelNY = (gcnew System::Windows::Forms::Label());
			this->labelNX = (gcnew System::Windows::Forms::Label());
			this->labelINZ = (gcnew System::Windows::Forms::Label());
			this->labelINY = (gcnew System::Windows::Forms::Label());
			this->labelINX = (gcnew System::Windows::Forms::Label());
			this->labelERR = (gcnew System::Windows::Forms::Label());
			this->labelM30 = (gcnew System::Windows::Forms::Label());
			this->labelPY = (gcnew System::Windows::Forms::Label());
			this->labelPX = (gcnew System::Windows::Forms::Label());
			this->labelHY = (gcnew System::Windows::Forms::Label());
			this->labelHX = (gcnew System::Windows::Forms::Label());
			this->labelPGM = (gcnew System::Windows::Forms::Label());
			this->labelM00 = (gcnew System::Windows::Forms::Label());
			this->labelHZ = (gcnew System::Windows::Forms::Label());
			this->labelPZ = (gcnew System::Windows::Forms::Label());
			this->X = (gcnew System::Windows::Forms::Label());
			this->Y = (gcnew System::Windows::Forms::Label());
			this->Z = (gcnew System::Windows::Forms::Label());
			this->labelW = (gcnew System::Windows::Forms::Label());
			this->labelV = (gcnew System::Windows::Forms::Label());
			this->labelU = (gcnew System::Windows::Forms::Label());
			this->W = (gcnew System::Windows::Forms::Label());
			this->V = (gcnew System::Windows::Forms::Label());
			this->U = (gcnew System::Windows::Forms::Label());
			this->richTextBoxNC = (gcnew System::Windows::Forms::RichTextBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelHour = (gcnew System::Windows::Forms::Label());
			this->labelYear = (gcnew System::Windows::Forms::Label());
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->richTextBoxFilePath = (gcnew System::Windows::Forms::RichTextBox());
			this->labelZ = (gcnew System::Windows::Forms::Label());
			this->labelY = (gcnew System::Windows::Forms::Label());
			this->labelX = (gcnew System::Windows::Forms::Label());
			this->buttonXPlus = (gcnew System::Windows::Forms::Button());
			this->buttonXMinus = (gcnew System::Windows::Forms::Button());
			this->buttonUVW = (gcnew System::Windows::Forms::Button());
			this->buttonYPlus = (gcnew System::Windows::Forms::Button());
			this->buttonYMinus = (gcnew System::Windows::Forms::Button());
			this->buttonZMinus = (gcnew System::Windows::Forms::Button());
			this->buttonZPlus = (gcnew System::Windows::Forms::Button());
			this->buttonX1 = (gcnew System::Windows::Forms::Button());
			this->buttonX10 = (gcnew System::Windows::Forms::Button());
			this->buttonX100 = (gcnew System::Windows::Forms::Button());
			this->buttonTeachEnd = (gcnew System::Windows::Forms::Button());
			this->buttonRecord = (gcnew System::Windows::Forms::Button());
			this->buttonTeachStart = (gcnew System::Windows::Forms::Button());
			this->buttonSB = (gcnew System::Windows::Forms::Button());
			this->buttonFH = (gcnew System::Windows::Forms::Button());
			this->buttonM01 = (gcnew System::Windows::Forms::Button());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->buttonMDI = (gcnew System::Windows::Forms::Button());
			this->buttonMEM = (gcnew System::Windows::Forms::Button());
			this->buttonWHEEL = (gcnew System::Windows::Forms::Button());
			this->buttonJOG = (gcnew System::Windows::Forms::Button());
			this->buttonTEACH = (gcnew System::Windows::Forms::Button());
			this->buttonParameter = (gcnew System::Windows::Forms::Button());
			this->buttonAnalog = (gcnew System::Windows::Forms::Button());
			this->buttonDiagnosis = (gcnew System::Windows::Forms::Button());
			this->buttonEmergencyStop = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timerReal = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerNonreal = (gcnew System::Windows::Forms::Timer(this->components));
			this->trackBar = (gcnew System::Windows::Forms::TrackBar());
			this->labelFeedOverride = (gcnew System::Windows::Forms::Label());
			this->buttonHOME = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->labelUPulse = (gcnew System::Windows::Forms::Label());
			this->labelVPulse = (gcnew System::Windows::Forms::Label());
			this->labelWPulse = (gcnew System::Windows::Forms::Label());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 8;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				49.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50.66667F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				79)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				72)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				78)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				72)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				72)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				97)));
			this->tableLayoutPanel1->Controls->Add(this->labelNZ, 7, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelNY, 6, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelNX, 5, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelINZ, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelINY, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelINX, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelERR, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelM30, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelPY, 6, 0);
			this->tableLayoutPanel1->Controls->Add(this->labelPX, 5, 0);
			this->tableLayoutPanel1->Controls->Add(this->labelHY, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->labelHX, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->labelPGM, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->labelM00, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->labelHZ, 7, 0);
			this->tableLayoutPanel1->Controls->Add(this->labelPZ, 4, 0);
			this->tableLayoutPanel1->Font = (gcnew System::Drawing::Font(L"Consolas", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(236, 22);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(600, 61);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// labelNZ
			// 
			this->labelNZ->AutoSize = true;
			this->labelNZ->Location = System::Drawing::Point(505, 30);
			this->labelNZ->Name = L"labelNZ";
			this->labelNZ->Size = System::Drawing::Size(30, 22);
			this->labelNZ->TabIndex = 15;
			this->labelNZ->Text = L"NZ";
			// 
			// labelNY
			// 
			this->labelNY->AutoSize = true;
			this->labelNY->Location = System::Drawing::Point(433, 30);
			this->labelNY->Name = L"labelNY";
			this->labelNY->Size = System::Drawing::Size(30, 22);
			this->labelNY->TabIndex = 14;
			this->labelNY->Text = L"NY";
			// 
			// labelNX
			// 
			this->labelNX->AutoSize = true;
			this->labelNX->Location = System::Drawing::Point(361, 30);
			this->labelNX->Name = L"labelNX";
			this->labelNX->Size = System::Drawing::Size(30, 22);
			this->labelNX->TabIndex = 13;
			this->labelNX->Text = L"NX";
			// 
			// labelINZ
			// 
			this->labelINZ->AutoSize = true;
			this->labelINZ->Location = System::Drawing::Point(283, 30);
			this->labelINZ->Name = L"labelINZ";
			this->labelINZ->Size = System::Drawing::Size(40, 22);
			this->labelINZ->TabIndex = 12;
			this->labelINZ->Text = L"INZ";
			// 
			// labelINY
			// 
			this->labelINY->AutoSize = true;
			this->labelINY->Location = System::Drawing::Point(211, 30);
			this->labelINY->Name = L"labelINY";
			this->labelINY->Size = System::Drawing::Size(40, 22);
			this->labelINY->TabIndex = 11;
			this->labelINY->Text = L"INY";
			// 
			// labelINX
			// 
			this->labelINX->AutoSize = true;
			this->labelINX->Location = System::Drawing::Point(132, 30);
			this->labelINX->Name = L"labelINX";
			this->labelINX->Size = System::Drawing::Size(40, 22);
			this->labelINX->TabIndex = 10;
			this->labelINX->Text = L"INX";
			// 
			// labelERR
			// 
			this->labelERR->AutoSize = true;
			this->labelERR->Location = System::Drawing::Point(67, 30);
			this->labelERR->Name = L"labelERR";
			this->labelERR->Size = System::Drawing::Size(40, 22);
			this->labelERR->TabIndex = 9;
			this->labelERR->Text = L"ERR";
			// 
			// labelM30
			// 
			this->labelM30->AutoSize = true;
			this->labelM30->Location = System::Drawing::Point(3, 30);
			this->labelM30->Name = L"labelM30";
			this->labelM30->Size = System::Drawing::Size(40, 22);
			this->labelM30->TabIndex = 8;
			this->labelM30->Text = L"M30";
			// 
			// labelPY
			// 
			this->labelPY->AutoSize = true;
			this->labelPY->Location = System::Drawing::Point(433, 0);
			this->labelPY->Name = L"labelPY";
			this->labelPY->Size = System::Drawing::Size(30, 22);
			this->labelPY->TabIndex = 6;
			this->labelPY->Text = L"PY";
			// 
			// labelPX
			// 
			this->labelPX->AutoSize = true;
			this->labelPX->Location = System::Drawing::Point(361, 0);
			this->labelPX->Name = L"labelPX";
			this->labelPX->Size = System::Drawing::Size(30, 22);
			this->labelPX->TabIndex = 5;
			this->labelPX->Text = L"PX";
			// 
			// labelHY
			// 
			this->labelHY->AutoSize = true;
			this->labelHY->Location = System::Drawing::Point(211, 0);
			this->labelHY->Name = L"labelHY";
			this->labelHY->Size = System::Drawing::Size(30, 22);
			this->labelHY->TabIndex = 3;
			this->labelHY->Text = L"HY";
			// 
			// labelHX
			// 
			this->labelHX->AutoSize = true;
			this->labelHX->Location = System::Drawing::Point(132, 0);
			this->labelHX->Name = L"labelHX";
			this->labelHX->Size = System::Drawing::Size(30, 22);
			this->labelHX->TabIndex = 2;
			this->labelHX->Text = L"HX";
			// 
			// labelPGM
			// 
			this->labelPGM->AutoSize = true;
			this->labelPGM->Location = System::Drawing::Point(67, 0);
			this->labelPGM->Name = L"labelPGM";
			this->labelPGM->Size = System::Drawing::Size(40, 22);
			this->labelPGM->TabIndex = 1;
			this->labelPGM->Text = L"PGM";
			// 
			// labelM00
			// 
			this->labelM00->AutoSize = true;
			this->labelM00->Location = System::Drawing::Point(3, 0);
			this->labelM00->Name = L"labelM00";
			this->labelM00->Size = System::Drawing::Size(40, 22);
			this->labelM00->TabIndex = 0;
			this->labelM00->Text = L"M00";
			// 
			// labelHZ
			// 
			this->labelHZ->AutoSize = true;
			this->labelHZ->Location = System::Drawing::Point(505, 0);
			this->labelHZ->Name = L"labelHZ";
			this->labelHZ->Size = System::Drawing::Size(30, 22);
			this->labelHZ->TabIndex = 4;
			this->labelHZ->Text = L"HZ";
			// 
			// labelPZ
			// 
			this->labelPZ->AutoSize = true;
			this->labelPZ->Location = System::Drawing::Point(283, 0);
			this->labelPZ->Name = L"labelPZ";
			this->labelPZ->Size = System::Drawing::Size(30, 22);
			this->labelPZ->TabIndex = 7;
			this->labelPZ->Text = L"PZ";
			// 
			// X
			// 
			this->X->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->X->Font = (gcnew System::Drawing::Font(L"Consolas", 15));
			this->X->Location = System::Drawing::Point(25, 99);
			this->X->Name = L"X";
			this->X->Size = System::Drawing::Size(57, 36);
			this->X->TabIndex = 1;
			this->X->Text = L"X";
			this->X->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Y
			// 
			this->Y->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Y->Font = (gcnew System::Drawing::Font(L"Consolas", 15));
			this->Y->Location = System::Drawing::Point(25, 148);
			this->Y->Name = L"Y";
			this->Y->Size = System::Drawing::Size(57, 37);
			this->Y->TabIndex = 2;
			this->Y->Text = L"Y";
			this->Y->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Z
			// 
			this->Z->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Z->Font = (gcnew System::Drawing::Font(L"Consolas", 15));
			this->Z->Location = System::Drawing::Point(25, 196);
			this->Z->Name = L"Z";
			this->Z->Size = System::Drawing::Size(57, 33);
			this->Z->TabIndex = 3;
			this->Z->Text = L"Z";
			this->Z->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelW
			// 
			this->labelW->BackColor = System::Drawing::Color::Silver;
			this->labelW->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->labelW->Location = System::Drawing::Point(83, 355);
			this->labelW->Name = L"labelW";
			this->labelW->Size = System::Drawing::Size(85, 28);
			this->labelW->TabIndex = 12;
			this->labelW->Text = L"0.000";
			this->labelW->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelV
			// 
			this->labelV->BackColor = System::Drawing::Color::Silver;
			this->labelV->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->labelV->Location = System::Drawing::Point(83, 322);
			this->labelV->Name = L"labelV";
			this->labelV->Size = System::Drawing::Size(85, 28);
			this->labelV->TabIndex = 11;
			this->labelV->Text = L"0.000";
			this->labelV->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelU
			// 
			this->labelU->BackColor = System::Drawing::Color::Silver;
			this->labelU->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->labelU->Location = System::Drawing::Point(83, 286);
			this->labelU->Name = L"labelU";
			this->labelU->Size = System::Drawing::Size(85, 28);
			this->labelU->TabIndex = 10;
			this->labelU->Text = L"0.000";
			this->labelU->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// W
			// 
			this->W->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->W->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->W->Location = System::Drawing::Point(27, 355);
			this->W->Name = L"W";
			this->W->Size = System::Drawing::Size(44, 28);
			this->W->TabIndex = 9;
			this->W->Text = L"W";
			this->W->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// V
			// 
			this->V->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->V->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->V->Location = System::Drawing::Point(27, 322);
			this->V->Name = L"V";
			this->V->Size = System::Drawing::Size(44, 28);
			this->V->TabIndex = 8;
			this->V->Text = L"V";
			this->V->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// U
			// 
			this->U->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->U->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->U->Location = System::Drawing::Point(27, 286);
			this->U->Name = L"U";
			this->U->Size = System::Drawing::Size(44, 28);
			this->U->TabIndex = 7;
			this->U->Text = L"U";
			this->U->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// richTextBoxNC
			// 
			this->richTextBoxNC->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->richTextBoxNC->Location = System::Drawing::Point(257, 99);
			this->richTextBoxNC->Name = L"richTextBoxNC";
			this->richTextBoxNC->Size = System::Drawing::Size(367, 131);
			this->richTextBoxNC->TabIndex = 13;
			this->richTextBoxNC->Text = L"";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->Controls->Add(this->labelHour, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->labelYear, 0, 0);
			this->tableLayoutPanel2->Font = (gcnew System::Drawing::Font(L"Consolas", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tableLayoutPanel2->Location = System::Drawing::Point(864, 22);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(119, 62);
			this->tableLayoutPanel2->TabIndex = 14;
			// 
			// labelHour
			// 
			this->labelHour->AutoSize = true;
			this->labelHour->Location = System::Drawing::Point(3, 31);
			this->labelHour->Name = L"labelHour";
			this->labelHour->Size = System::Drawing::Size(110, 22);
			this->labelHour->TabIndex = 1;
			this->labelHour->Text = L"label_hour";
			// 
			// labelYear
			// 
			this->labelYear->AutoSize = true;
			this->labelYear->Location = System::Drawing::Point(3, 0);
			this->labelYear->Name = L"labelYear";
			this->labelYear->Size = System::Drawing::Size(110, 22);
			this->labelYear->TabIndex = 0;
			this->labelYear->Text = L"label_year";
			// 
			// buttonOpen
			// 
			this->buttonOpen->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonOpen->Location = System::Drawing::Point(24, 241);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(71, 32);
			this->buttonOpen->TabIndex = 15;
			this->buttonOpen->Text = L"OPEN";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &Form1::buttonOpen_Click);
			// 
			// richTextBoxFilePath
			// 
			this->richTextBoxFilePath->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->richTextBoxFilePath->Location = System::Drawing::Point(101, 241);
			this->richTextBoxFilePath->Name = L"richTextBoxFilePath";
			this->richTextBoxFilePath->Size = System::Drawing::Size(525, 32);
			this->richTextBoxFilePath->TabIndex = 16;
			this->richTextBoxFilePath->Text = L"";
			// 
			// labelZ
			// 
			this->labelZ->BackColor = System::Drawing::Color::Silver;
			this->labelZ->Font = (gcnew System::Drawing::Font(L"Consolas", 15));
			this->labelZ->Location = System::Drawing::Point(97, 196);
			this->labelZ->Name = L"labelZ";
			this->labelZ->Size = System::Drawing::Size(141, 34);
			this->labelZ->TabIndex = 20;
			this->labelZ->Text = L"00.000";
			this->labelZ->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelY
			// 
			this->labelY->BackColor = System::Drawing::Color::Silver;
			this->labelY->Font = (gcnew System::Drawing::Font(L"Consolas", 15));
			this->labelY->Location = System::Drawing::Point(96, 148);
			this->labelY->Name = L"labelY";
			this->labelY->Size = System::Drawing::Size(141, 37);
			this->labelY->TabIndex = 19;
			this->labelY->Text = L"75.000";
			this->labelY->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelX
			// 
			this->labelX->BackColor = System::Drawing::Color::Silver;
			this->labelX->Font = (gcnew System::Drawing::Font(L"Consolas", 15));
			this->labelX->Location = System::Drawing::Point(97, 99);
			this->labelX->Name = L"labelX";
			this->labelX->Size = System::Drawing::Size(141, 36);
			this->labelX->TabIndex = 18;
			this->labelX->Text = L"75.000";
			this->labelX->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// buttonXPlus
			// 
			this->buttonXPlus->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonXPlus->Location = System::Drawing::Point(188, 286);
			this->buttonXPlus->Name = L"buttonXPlus";
			this->buttonXPlus->Size = System::Drawing::Size(80, 29);
			this->buttonXPlus->TabIndex = 21;
			this->buttonXPlus->Text = L"X+";
			this->buttonXPlus->UseVisualStyleBackColor = true;
			this->buttonXPlus->Click += gcnew System::EventHandler(this, &Form1::buttonXPlus_Click);
			this->buttonXPlus->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::buttonXPlus_MouseDown);
			this->buttonXPlus->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::buttonXPlus_MouseUp);
			// 
			// buttonXMinus
			// 
			this->buttonXMinus->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonXMinus->Location = System::Drawing::Point(279, 286);
			this->buttonXMinus->Name = L"buttonXMinus";
			this->buttonXMinus->Size = System::Drawing::Size(77, 29);
			this->buttonXMinus->TabIndex = 24;
			this->buttonXMinus->Text = L"X-";
			this->buttonXMinus->UseVisualStyleBackColor = true;
			this->buttonXMinus->Click += gcnew System::EventHandler(this, &Form1::buttonXMinus_Click);
			this->buttonXMinus->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::buttonXMinus_MouseDown);
			this->buttonXMinus->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::buttonXMinus_MouseUp);
			// 
			// buttonUVW
			// 
			this->buttonUVW->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonUVW->Location = System::Drawing::Point(236, 321);
			this->buttonUVW->Name = L"buttonUVW";
			this->buttonUVW->Size = System::Drawing::Size(70, 27);
			this->buttonUVW->TabIndex = 27;
			this->buttonUVW->Text = L"UVW";
			this->buttonUVW->UseVisualStyleBackColor = true;
			this->buttonUVW->Click += gcnew System::EventHandler(this, &Form1::buttonUVW_Click);
			// 
			// buttonYPlus
			// 
			this->buttonYPlus->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonYPlus->Location = System::Drawing::Point(188, 321);
			this->buttonYPlus->Name = L"buttonYPlus";
			this->buttonYPlus->Size = System::Drawing::Size(42, 28);
			this->buttonYPlus->TabIndex = 29;
			this->buttonYPlus->Text = L"Y+";
			this->buttonYPlus->UseVisualStyleBackColor = true;
			this->buttonYPlus->Click += gcnew System::EventHandler(this, &Form1::buttonYPlus_Click);
			this->buttonYPlus->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::buttonYPlus_MouseDown);
			this->buttonYPlus->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::buttonYPlus_MouseUp);
			// 
			// buttonYMinus
			// 
			this->buttonYMinus->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonYMinus->Location = System::Drawing::Point(312, 321);
			this->buttonYMinus->Name = L"buttonYMinus";
			this->buttonYMinus->Size = System::Drawing::Size(44, 28);
			this->buttonYMinus->TabIndex = 28;
			this->buttonYMinus->Text = L"Y-";
			this->buttonYMinus->UseVisualStyleBackColor = true;
			this->buttonYMinus->Click += gcnew System::EventHandler(this, &Form1::buttonYMinus_Click);
			this->buttonYMinus->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::buttonYMinus_MouseDown);
			this->buttonYMinus->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::buttonYMinus_MouseUp);
			// 
			// buttonZMinus
			// 
			this->buttonZMinus->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonZMinus->Location = System::Drawing::Point(277, 355);
			this->buttonZMinus->Name = L"buttonZMinus";
			this->buttonZMinus->Size = System::Drawing::Size(79, 28);
			this->buttonZMinus->TabIndex = 31;
			this->buttonZMinus->Text = L"Z-";
			this->buttonZMinus->UseVisualStyleBackColor = true;
			this->buttonZMinus->Click += gcnew System::EventHandler(this, &Form1::buttonZMinus_Click);
			this->buttonZMinus->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::buttonZMinus_MouseDown);
			this->buttonZMinus->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::buttonZMinus_MouseUp);
			// 
			// buttonZPlus
			// 
			this->buttonZPlus->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonZPlus->Location = System::Drawing::Point(188, 355);
			this->buttonZPlus->Name = L"buttonZPlus";
			this->buttonZPlus->Size = System::Drawing::Size(80, 28);
			this->buttonZPlus->TabIndex = 30;
			this->buttonZPlus->Text = L"Z+";
			this->buttonZPlus->UseVisualStyleBackColor = true;
			this->buttonZPlus->Click += gcnew System::EventHandler(this, &Form1::buttonZPlus_Click);
			this->buttonZPlus->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::buttonZPlus_MouseDown);
			this->buttonZPlus->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::buttonZPlus_MouseUp);
			// 
			// buttonX1
			// 
			this->buttonX1->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonX1->Location = System::Drawing::Point(364, 288);
			this->buttonX1->Name = L"buttonX1";
			this->buttonX1->Size = System::Drawing::Size(67, 28);
			this->buttonX1->TabIndex = 32;
			this->buttonX1->Text = L"X1";
			this->buttonX1->UseVisualStyleBackColor = true;
			this->buttonX1->Click += gcnew System::EventHandler(this, &Form1::buttonX1_Click);
			// 
			// buttonX10
			// 
			this->buttonX10->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonX10->Location = System::Drawing::Point(364, 322);
			this->buttonX10->Name = L"buttonX10";
			this->buttonX10->Size = System::Drawing::Size(67, 28);
			this->buttonX10->TabIndex = 33;
			this->buttonX10->Text = L"X10";
			this->buttonX10->UseVisualStyleBackColor = true;
			this->buttonX10->Click += gcnew System::EventHandler(this, &Form1::buttonX10_Click);
			// 
			// buttonX100
			// 
			this->buttonX100->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonX100->Location = System::Drawing::Point(365, 356);
			this->buttonX100->Name = L"buttonX100";
			this->buttonX100->Size = System::Drawing::Size(67, 28);
			this->buttonX100->TabIndex = 34;
			this->buttonX100->Text = L"X100";
			this->buttonX100->UseVisualStyleBackColor = true;
			this->buttonX100->Click += gcnew System::EventHandler(this, &Form1::buttonX100_Click);
			// 
			// buttonTeachEnd
			// 
			this->buttonTeachEnd->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonTeachEnd->Location = System::Drawing::Point(440, 356);
			this->buttonTeachEnd->Name = L"buttonTeachEnd";
			this->buttonTeachEnd->Size = System::Drawing::Size(115, 28);
			this->buttonTeachEnd->TabIndex = 37;
			this->buttonTeachEnd->Text = L"TEACH END";
			this->buttonTeachEnd->UseVisualStyleBackColor = true;
			this->buttonTeachEnd->Click += gcnew System::EventHandler(this, &Form1::buttonTeachEnd_Click);
			// 
			// buttonRecord
			// 
			this->buttonRecord->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonRecord->Location = System::Drawing::Point(439, 322);
			this->buttonRecord->Name = L"buttonRecord";
			this->buttonRecord->Size = System::Drawing::Size(115, 28);
			this->buttonRecord->TabIndex = 36;
			this->buttonRecord->Text = L"RECORD";
			this->buttonRecord->UseVisualStyleBackColor = true;
			this->buttonRecord->Click += gcnew System::EventHandler(this, &Form1::buttonRecord_Click);
			// 
			// buttonTeachStart
			// 
			this->buttonTeachStart->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonTeachStart->Location = System::Drawing::Point(439, 288);
			this->buttonTeachStart->Name = L"buttonTeachStart";
			this->buttonTeachStart->Size = System::Drawing::Size(115, 28);
			this->buttonTeachStart->TabIndex = 35;
			this->buttonTeachStart->Text = L"TEACH START";
			this->buttonTeachStart->UseVisualStyleBackColor = true;
			this->buttonTeachStart->Click += gcnew System::EventHandler(this, &Form1::buttonTeachStart_Click);
			// 
			// buttonSB
			// 
			this->buttonSB->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonSB->Location = System::Drawing::Point(568, 357);
			this->buttonSB->Name = L"buttonSB";
			this->buttonSB->Size = System::Drawing::Size(59, 28);
			this->buttonSB->TabIndex = 40;
			this->buttonSB->Text = L"SB";
			this->buttonSB->UseVisualStyleBackColor = true;
			this->buttonSB->Click += gcnew System::EventHandler(this, &Form1::buttonSB_Click);
			// 
			// buttonFH
			// 
			this->buttonFH->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonFH->Location = System::Drawing::Point(567, 323);
			this->buttonFH->Name = L"buttonFH";
			this->buttonFH->Size = System::Drawing::Size(59, 28);
			this->buttonFH->TabIndex = 39;
			this->buttonFH->Text = L"FH";
			this->buttonFH->UseVisualStyleBackColor = true;
			this->buttonFH->Click += gcnew System::EventHandler(this, &Form1::buttonFH_Click);
			// 
			// buttonM01
			// 
			this->buttonM01->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonM01->Location = System::Drawing::Point(567, 289);
			this->buttonM01->Name = L"buttonM01";
			this->buttonM01->Size = System::Drawing::Size(59, 28);
			this->buttonM01->TabIndex = 38;
			this->buttonM01->Text = L"M01";
			this->buttonM01->UseVisualStyleBackColor = true;
			this->buttonM01->Click += gcnew System::EventHandler(this, &Form1::buttonM01_Click);
			// 
			// buttonReset
			// 
			this->buttonReset->BackColor = System::Drawing::Color::Yellow;
			this->buttonReset->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonReset->Location = System::Drawing::Point(727, 428);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(77, 83);
			this->buttonReset->TabIndex = 42;
			this->buttonReset->Text = L"RESET";
			this->buttonReset->UseVisualStyleBackColor = false;
			this->buttonReset->Click += gcnew System::EventHandler(this, &Form1::buttonReset_Click);
			// 
			// buttonStart
			// 
			this->buttonStart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonStart->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonStart->Location = System::Drawing::Point(644, 428);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(77, 83);
			this->buttonStart->TabIndex = 41;
			this->buttonStart->Text = L"START";
			this->buttonStart->UseVisualStyleBackColor = false;
			this->buttonStart->Click += gcnew System::EventHandler(this, &Form1::buttonStart_Click);
			// 
			// buttonMDI
			// 
			this->buttonMDI->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->buttonMDI->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonMDI->Location = System::Drawing::Point(86, 522);
			this->buttonMDI->Name = L"buttonMDI";
			this->buttonMDI->Size = System::Drawing::Size(70, 46);
			this->buttonMDI->TabIndex = 46;
			this->buttonMDI->Text = L"MDI";
			this->buttonMDI->UseVisualStyleBackColor = false;
			this->buttonMDI->Click += gcnew System::EventHandler(this, &Form1::buttonMDI_Click);
			// 
			// buttonMEM
			// 
			this->buttonMEM->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->buttonMEM->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonMEM->Location = System::Drawing::Point(12, 522);
			this->buttonMEM->Name = L"buttonMEM";
			this->buttonMEM->Size = System::Drawing::Size(70, 46);
			this->buttonMEM->TabIndex = 45;
			this->buttonMEM->Text = L"MEM";
			this->buttonMEM->UseVisualStyleBackColor = false;
			this->buttonMEM->Click += gcnew System::EventHandler(this, &Form1::buttonMEM_Click);
			// 
			// buttonWHEEL
			// 
			this->buttonWHEEL->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->buttonWHEEL->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonWHEEL->Location = System::Drawing::Point(234, 522);
			this->buttonWHEEL->Name = L"buttonWHEEL";
			this->buttonWHEEL->Size = System::Drawing::Size(70, 46);
			this->buttonWHEEL->TabIndex = 48;
			this->buttonWHEEL->Text = L"WHEEL";
			this->buttonWHEEL->UseVisualStyleBackColor = false;
			this->buttonWHEEL->Click += gcnew System::EventHandler(this, &Form1::buttonWHEEL_Click);
			// 
			// buttonJOG
			// 
			this->buttonJOG->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->buttonJOG->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonJOG->Location = System::Drawing::Point(160, 522);
			this->buttonJOG->Name = L"buttonJOG";
			this->buttonJOG->Size = System::Drawing::Size(70, 46);
			this->buttonJOG->TabIndex = 47;
			this->buttonJOG->Text = L"JOG";
			this->buttonJOG->UseVisualStyleBackColor = false;
			this->buttonJOG->Click += gcnew System::EventHandler(this, &Form1::buttonJOG_Click);
			// 
			// buttonTEACH
			// 
			this->buttonTEACH->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->buttonTEACH->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonTEACH->Location = System::Drawing::Point(307, 522);
			this->buttonTEACH->Name = L"buttonTEACH";
			this->buttonTEACH->Size = System::Drawing::Size(70, 46);
			this->buttonTEACH->TabIndex = 49;
			this->buttonTEACH->Text = L"TEACH";
			this->buttonTEACH->UseVisualStyleBackColor = false;
			this->buttonTEACH->Click += gcnew System::EventHandler(this, &Form1::buttonTEACH_Click);
			// 
			// buttonParameter
			// 
			this->buttonParameter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonParameter->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonParameter->Location = System::Drawing::Point(459, 522);
			this->buttonParameter->Name = L"buttonParameter";
			this->buttonParameter->Size = System::Drawing::Size(124, 46);
			this->buttonParameter->TabIndex = 51;
			this->buttonParameter->Text = L"PARAMETER";
			this->buttonParameter->UseVisualStyleBackColor = false;
			// 
			// buttonAnalog
			// 
			this->buttonAnalog->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonAnalog->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonAnalog->Location = System::Drawing::Point(589, 522);
			this->buttonAnalog->Name = L"buttonAnalog";
			this->buttonAnalog->Size = System::Drawing::Size(120, 46);
			this->buttonAnalog->TabIndex = 52;
			this->buttonAnalog->Text = L"SIMULATION";
			this->buttonAnalog->UseVisualStyleBackColor = false;
			// 
			// buttonDiagnosis
			// 
			this->buttonDiagnosis->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonDiagnosis->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonDiagnosis->Location = System::Drawing::Point(715, 523);
			this->buttonDiagnosis->Name = L"buttonDiagnosis";
			this->buttonDiagnosis->Size = System::Drawing::Size(114, 46);
			this->buttonDiagnosis->TabIndex = 53;
			this->buttonDiagnosis->Text = L"DIAGNOSIS";
			this->buttonDiagnosis->UseVisualStyleBackColor = false;
			// 
			// buttonEmergencyStop
			// 
			this->buttonEmergencyStop->BackColor = System::Drawing::Color::Red;
			this->buttonEmergencyStop->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonEmergencyStop->Location = System::Drawing::Point(835, 522);
			this->buttonEmergencyStop->Name = L"buttonEmergencyStop";
			this->buttonEmergencyStop->Size = System::Drawing::Size(161, 49);
			this->buttonEmergencyStop->TabIndex = 56;
			this->buttonEmergencyStop->Text = L"EMERGENCY STOP";
			this->buttonEmergencyStop->UseVisualStyleBackColor = false;
			this->buttonEmergencyStop->Click += gcnew System::EventHandler(this, &Form1::buttonEmergencyStop_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// timerReal
			// 
			this->timerReal->Enabled = true;
			this->timerReal->Interval = 20;
			this->timerReal->Tick += gcnew System::EventHandler(this, &Form1::timerReal_Tick);
			// 
			// timerNonreal
			// 
			this->timerNonreal->Enabled = true;
			this->timerNonreal->Interval = 50;
			this->timerNonreal->Tick += gcnew System::EventHandler(this, &Form1::timerNonreal_Tick);
			// 
			// trackBar
			// 
			this->trackBar->Location = System::Drawing::Point(820, 467);
			this->trackBar->Maximum = 200;
			this->trackBar->Name = L"trackBar";
			this->trackBar->Size = System::Drawing::Size(176, 56);
			this->trackBar->TabIndex = 5;
			this->trackBar->TickFrequency = 10;
			this->trackBar->Value = 100;
			this->trackBar->Scroll += gcnew System::EventHandler(this, &Form1::trackBar_Scroll);
			// 
			// labelFeedOverride
			// 
			this->labelFeedOverride->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelFeedOverride->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->labelFeedOverride->Location = System::Drawing::Point(810, 444);
			this->labelFeedOverride->Name = L"labelFeedOverride";
			this->labelFeedOverride->Size = System::Drawing::Size(193, 20);
			this->labelFeedOverride->TabIndex = 58;
			this->labelFeedOverride->Text = L"Feed Override 100%";
			this->labelFeedOverride->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonHOME
			// 
			this->buttonHOME->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->buttonHOME->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonHOME->Location = System::Drawing::Point(383, 522);
			this->buttonHOME->Name = L"buttonHOME";
			this->buttonHOME->Size = System::Drawing::Size(70, 46);
			this->buttonHOME->TabIndex = 59;
			this->buttonHOME->Text = L"HOME";
			this->buttonHOME->UseVisualStyleBackColor = false;
			this->buttonHOME->Click += gcnew System::EventHandler(this, &Form1::buttonHOME_Click);
			// 
			// chart1
			// 
			chartArea1->AxisX->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::NotSet;
			chartArea1->AxisX->Maximum = 300;
			chartArea1->AxisX->Minimum = 0;
			chartArea1->AxisY->Maximum = 70;
			chartArea1->AxisY->Minimum = 0;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(24, 396);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Legend = L"Legend1";
			series1->Name = L"feedrate";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(602, 115);
			this->chart1->TabIndex = 60;
			this->chart1->Text = L"chart1";
			// 
			// chart2
			// 
			chartArea2->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea2->AxisX->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea2->AxisX->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea2->AxisX->Maximum = 150;
			chartArea2->AxisX->Minimum = -150;
			chartArea2->AxisY->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea2->AxisY->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea2->AxisY->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea2->AxisY->Maximum = 150;
			chartArea2->AxisY->Minimum = -150;
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Enabled = false;
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(644, 99);
			this->chart2->Name = L"chart2";
			this->chart2->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Pastel;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"location";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Legend = L"Legend1";
			series3->Name = L"location2";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series4->Legend = L"Legend1";
			series4->Name = L"location3";
			this->chart2->Series->Add(series2);
			this->chart2->Series->Add(series3);
			this->chart2->Series->Add(series4);
			this->chart2->Size = System::Drawing::Size(339, 286);
			this->chart2->TabIndex = 61;
			this->chart2->Text = L"chart2";
			// 
			// labelUPulse
			// 
			this->labelUPulse->AutoSize = true;
			this->labelUPulse->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->labelUPulse->Location = System::Drawing::Point(30, 22);
			this->labelUPulse->Name = L"labelUPulse";
			this->labelUPulse->Size = System::Drawing::Size(96, 18);
			this->labelUPulse->TabIndex = 62;
			this->labelUPulse->Text = L"labelUPulse";
			// 
			// labelVPulse
			// 
			this->labelVPulse->AutoSize = true;
			this->labelVPulse->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->labelVPulse->Location = System::Drawing::Point(30, 37);
			this->labelVPulse->Name = L"labelVPulse";
			this->labelVPulse->Size = System::Drawing::Size(96, 18);
			this->labelVPulse->TabIndex = 63;
			this->labelVPulse->Text = L"labelVPulse";
			// 
			// labelWPulse
			// 
			this->labelWPulse->AutoSize = true;
			this->labelWPulse->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->labelWPulse->Location = System::Drawing::Point(30, 52);
			this->labelWPulse->Name = L"labelWPulse";
			this->labelWPulse->Size = System::Drawing::Size(96, 18);
			this->labelWPulse->TabIndex = 64;
			this->labelWPulse->Text = L"labelWPulse";
			// 
			// buttonClear
			// 
			this->buttonClear->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
			this->buttonClear->Location = System::Drawing::Point(908, 384);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(75, 36);
			this->buttonClear->TabIndex = 65;
			this->buttonClear->Text = L"Clear";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Form1::buttonClear_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1006, 574);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->labelWPulse);
			this->Controls->Add(this->labelVPulse);
			this->Controls->Add(this->labelUPulse);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->buttonHOME);
			this->Controls->Add(this->labelFeedOverride);
			this->Controls->Add(this->trackBar);
			this->Controls->Add(this->buttonEmergencyStop);
			this->Controls->Add(this->buttonDiagnosis);
			this->Controls->Add(this->buttonAnalog);
			this->Controls->Add(this->buttonParameter);
			this->Controls->Add(this->buttonTEACH);
			this->Controls->Add(this->buttonWHEEL);
			this->Controls->Add(this->buttonJOG);
			this->Controls->Add(this->buttonMDI);
			this->Controls->Add(this->buttonMEM);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->buttonStart);
			this->Controls->Add(this->buttonSB);
			this->Controls->Add(this->buttonFH);
			this->Controls->Add(this->buttonM01);
			this->Controls->Add(this->buttonTeachEnd);
			this->Controls->Add(this->buttonRecord);
			this->Controls->Add(this->buttonTeachStart);
			this->Controls->Add(this->buttonX100);
			this->Controls->Add(this->buttonX10);
			this->Controls->Add(this->buttonX1);
			this->Controls->Add(this->buttonZMinus);
			this->Controls->Add(this->buttonZPlus);
			this->Controls->Add(this->buttonYPlus);
			this->Controls->Add(this->buttonYMinus);
			this->Controls->Add(this->buttonUVW);
			this->Controls->Add(this->buttonXMinus);
			this->Controls->Add(this->buttonXPlus);
			this->Controls->Add(this->labelZ);
			this->Controls->Add(this->labelY);
			this->Controls->Add(this->labelX);
			this->Controls->Add(this->richTextBoxFilePath);
			this->Controls->Add(this->buttonOpen);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->richTextBoxNC);
			this->Controls->Add(this->labelW);
			this->Controls->Add(this->labelV);
			this->Controls->Add(this->labelU);
			this->Controls->Add(this->W);
			this->Controls->Add(this->V);
			this->Controls->Add(this->U);
			this->Controls->Add(this->Z);
			this->Controls->Add(this->Y);
			this->Controls->Add(this->X);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Form1";
			this->Text = L"W";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

			cncDataPtr= &cncData;
			cncInit(cncDataPtr);

			#if HD_TIMER
						// init motion card
						initMotionCard(cncDataPtr->intpDataPtr->uvwStart[0], cncDataPtr->intpDataPtr->uvwStart[1], cncDataPtr->intpDataPtr->uvwStart[2], REAL_SAMPLING_TIME ,Timer_ISR_Function);
						// enable timer
						enableHDTimer(REAL_SAMPLING_TIME);	
						timerReal->Enabled		= true;
						timerNonreal->Enabled	= true;
			#else
						timerReal->Interval = REAL_SAMPLING_TIME;
						timerReal->Enabled		= true;
						timerNonreal->Enabled	= true;
			#endif

			 }

private: System::Void buttonOpen_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode== NULL_MODE)
			 {
				 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = MEM_MODE;
				 cncDataPtr->mmiDataPtr->formInput = true;
				 buttonMEM->BackColor = Color::SteelBlue;
				 buttonMDI->BackColor = Color::Silver;
				 buttonJOG->BackColor = Color::Silver;
				 buttonWHEEL->BackColor = Color::Silver;
				 buttonTEACH->BackColor = Color::Silver;
				 buttonHOME->BackColor = Color::Silver;
			 }
			 			 
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode== MEM_MODE )
			 {
				 openFileDialog1->InitialDirectory= "";
				 openFileDialog1->Filter = "文字檔(*.txt)|*.txt|所有檔案(*.)|*.*";
				 openFileDialog1->FilterIndex= 2;
				 openFileDialog1->DefaultExt= "*.txt";
				 openFileDialog1->FileName= "";
				 openFileDialog1->RestoreDirectory= true;
				 if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 richTextBoxFilePath->Text = openFileDialog1->FileName;
					 richTextBoxNC->LoadFile(openFileDialog1->FileName, RichTextBoxStreamType::PlainText);
					 strcpy_s( cncDataPtr->mmiDataPtr->ncFileName , 200,(char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( openFileDialog1->FileName) );
					 cncDataPtr->mmiDataPtr->ncFileValid = true;
					 cncDataPtr->mmiDataPtr->formInput = true;
				 }
			 }
			 if (cncDataPtr->mmiDataPtr->linkDataPtr->opMode == MDI_MODE)
			 {
				 char richTextBoxTmp[500];
				 for (int i=0; i<500; i++){
					 richTextBoxTmp[ i ] = ' '; //string to char
				 }
				 pin_ptr<const wchar_t> wch = PtrToStringChars(richTextBoxNC->Text); 
				 size_t  sizeInBytes = ((richTextBoxNC->Text->Length + 1) * 2);
				 size_t convertedChars = 0;
				 wcstombs_s(&convertedChars, richTextBoxTmp, sizeInBytes, wch, sizeInBytes);
				 std::fstream  file;
				 const char filename[]="mdi.txt";

				 file.open(filename, std::ios::out | std::ios::trunc); //clean the file context and write into txt file
				 file << richTextBoxTmp << std::endl;
				 file.close();
				 strcpy_s(cncDataPtr->mmiDataPtr->ncFileName, 200,filename);
				 richTextBoxFilePath->Text = "Already safed!";
				 cncDataPtr->mmiDataPtr->ncFileValid = true;
				 cncDataPtr->mmiDataPtr->formInput = true;
			 }			 


			}//buttonOpen_Click openFileDialog1

private: System::Void trackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			cncDataPtr->mmiDataPtr->feedOverride = trackBar->Value; //put the value of trackBar into mmiData.feedOverride
			cncDataPtr->mmiDataPtr->formInput = true;
			labelFeedOverride->Text = trackBar->Value.ToString() +"%";  //show on the label

		 }//trackBar

private: System::Void buttonFH_Click(System::Object^  sender, System::EventArgs^  e) {
			if (cncDataPtr->mmiDataPtr->feedHold == true)
			{
				cncDataPtr->mmiDataPtr->feedHold = false;
				cncDataPtr->mmiDataPtr->formInput = true;
				buttonFH->BackColor = Color::Silver;
			}
			else
			{
				cncDataPtr->mmiDataPtr->feedHold = true;
				cncDataPtr->mmiDataPtr->formInput = true;
				buttonFH->BackColor = Color::Red;
			}
		 }//buttonFH_Click

private: System::Void buttonM01_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (cncDataPtr->mmiDataPtr->M01 == true)
			 {
				 cncDataPtr->mmiDataPtr->M01 = false;
				 cncDataPtr->mmiDataPtr->formInput = true;
				 buttonM01->BackColor = Color::Silver;
			 }
			 else
			 {
				 cncDataPtr->mmiDataPtr->M01 = true;
				 cncDataPtr->mmiDataPtr->formInput = true;
				 buttonM01->BackColor = Color::Red;
			 }


		 }//buttonM01_Click

private: System::Void buttonSB_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (cncDataPtr->mmiDataPtr->singleBlock == true)
			 {
				 cncDataPtr->mmiDataPtr->singleBlock = false;
				 cncDataPtr->mmiDataPtr->formInput = true;
				 buttonSB->BackColor = Color::Silver;
			 }
			 else
			 {
				 cncDataPtr->mmiDataPtr->singleBlock = true;
				 cncDataPtr->mmiDataPtr->formInput = true;
				 buttonSB->BackColor = Color::Red;
			 }
		 
		 
		 
		 }



private: System::Void buttonMEM_Click(System::Object^  sender, System::EventArgs^  e) {

			cncDataPtr->mmiDataPtr->linkDataPtr->opMode = MEM_MODE;
			cncDataPtr->mmiDataPtr->formInput = true;
			buttonMEM->BackColor = Color::SteelBlue;
			buttonMDI->BackColor = Color::Silver;
			buttonJOG->BackColor = Color::Silver;
			buttonWHEEL->BackColor = Color::Silver;
			buttonTEACH->BackColor = Color::Silver;
			buttonHOME->BackColor = Color::Silver;
		 }
private: System::Void buttonMDI_Click(System::Object^  sender, System::EventArgs^  e) {
			 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = MDI_MODE;
			 cncDataPtr->mmiDataPtr->formInput = true;
			 buttonMEM->BackColor = Color::Silver;
			 buttonMDI->BackColor = Color::SteelBlue;
			 buttonJOG->BackColor = Color::Silver;
			 buttonWHEEL->BackColor = Color::Silver;
			 buttonTEACH->BackColor = Color::Silver;
			 buttonHOME->BackColor = Color::Silver;
		 }
private: System::Void buttonJOG_Click(System::Object^  sender, System::EventArgs^  e) {
			 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
			 cncDataPtr->mmiDataPtr->formInput = true;
			 buttonMEM->BackColor = Color::Silver;
			 buttonMDI->BackColor = Color::Silver;
			 buttonJOG->BackColor = Color::SteelBlue;
			 buttonWHEEL->BackColor = Color::Silver;
			 buttonTEACH->BackColor = Color::Silver;
			 buttonHOME->BackColor = Color::Silver;
		 }
private: System::Void buttonWHEEL_Click(System::Object^  sender, System::EventArgs^  e) {
			 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = WHEEL_MODE;
			 cncDataPtr->mmiDataPtr->formInput = true;
			 buttonMEM->BackColor = Color::Silver;
			 buttonMDI->BackColor = Color::Silver;
			 buttonJOG->BackColor = Color::Silver;
			 buttonWHEEL->BackColor = Color::SteelBlue;
			 buttonTEACH->BackColor = Color::Silver;
			 buttonHOME->BackColor = Color::Silver;
		 }
private: System::Void buttonTEACH_Click(System::Object^  sender, System::EventArgs^  e) {
			 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = TEACH_MODE;
			 cncDataPtr->mmiDataPtr->formInput = true;
			 buttonMEM->BackColor = Color::Silver;
			 buttonMDI->BackColor = Color::Silver;
			 buttonJOG->BackColor = Color::Silver;
			 buttonWHEEL->BackColor = Color::Silver;
			 buttonTEACH->BackColor = Color::SteelBlue;
			 buttonHOME->BackColor = Color::Silver;
		 }
private: System::Void buttonHOME_Click(System::Object^  sender, System::EventArgs^  e) {
			 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = HOME_MODE;
			 cncDataPtr->mmiDataPtr->formInput = true;
			 buttonMEM->BackColor = Color::Silver;
			 buttonMDI->BackColor = Color::Silver;
			 buttonJOG->BackColor = Color::Silver;
			 buttonWHEEL->BackColor = Color::Silver;
			 buttonTEACH->BackColor = Color::Silver;
			 buttonHOME->BackColor = Color::SteelBlue;
		 }
private: System::Void buttonUVW_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (cncDataPtr->mmiDataPtr->uvwxyz == false)  //false 是xyz
				 {
					 buttonXPlus->Text = L"U+";
					 buttonYPlus->Text = L"V+";
					 buttonZPlus->Text = L"W+";
					 buttonXMinus->Text = L"U-";
					 buttonYMinus->Text = L"V-";
					 buttonZMinus->Text = L"W-";
					 cncDataPtr->mmiDataPtr->formInput = true;
					 cncDataPtr->mmiDataPtr->uvwxyz = true ; //true is uvw
				 }
				 else
				 {
					 buttonXPlus->Text = L"X+";
					 buttonYPlus->Text = L"Y+";
					 buttonZPlus->Text = L"Z+";
					 buttonXMinus->Text = L"X-";
					 buttonYMinus->Text = L"Y-";
					 buttonZMinus->Text = L"Z-";
					 cncDataPtr->mmiDataPtr->formInput = true;
					 cncDataPtr->mmiDataPtr->uvwxyz = false;
				 }

		 }
private: System::Void buttonX1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode ==WHEEL_MODE)
			 {
				 if(cncDataPtr->mmiDataPtr->XButtonCheck[0]==false)
				 {
					 cncDataPtr->mmiDataPtr->XButtonCheck[0]=true;
					 cncDataPtr->mmiDataPtr->XButtonCheck[1]=false;
					cncDataPtr->mmiDataPtr->XButtonCheck[2]=false;
					 cncDataPtr->mmiDataPtr->formInput = true;
					 cncDataPtr->mmiDataPtr->wheelRatio=0.001;
					 buttonX1 ->BackColor = Color::LimeGreen;
					 buttonX10 ->BackColor = Color::Transparent;
					 buttonX100 ->BackColor = Color::Transparent;
				 }
				 else
				 {
					 cncDataPtr->mmiDataPtr->XButtonCheck[0]=false;
					 cncDataPtr->mmiDataPtr->XButtonCheck[1]=false;
					cncDataPtr->mmiDataPtr->XButtonCheck[2]=false;
					 buttonX1 ->BackColor = Color::Transparent;
					 buttonX10 ->BackColor = Color::Transparent;
					 buttonX100 ->BackColor = Color::Transparent;
				 }
				 
			 }
		 }
private: System::Void buttonX10_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode ==WHEEL_MODE)
			 {
				 if(cncDataPtr->mmiDataPtr->XButtonCheck[1]==false)
				 {
					 cncDataPtr->mmiDataPtr->XButtonCheck[0]=false;
					 cncDataPtr->mmiDataPtr->XButtonCheck[1]=true;
					 cncDataPtr->mmiDataPtr->XButtonCheck[2]=false;
					 cncDataPtr->mmiDataPtr->formInput = true;
					 cncDataPtr->mmiDataPtr->wheelRatio =0.01;
					 buttonX1 ->BackColor = Color::Transparent;
					 buttonX10 ->BackColor = Color::LimeGreen;
					 buttonX100 ->BackColor = Color::Transparent;
				 }
				 else
				 {
					 cncDataPtr->mmiDataPtr->XButtonCheck[0]=false;
					 cncDataPtr->mmiDataPtr->XButtonCheck[1]=false;
					 cncDataPtr->mmiDataPtr->XButtonCheck[2]=false;
					 buttonX1 ->BackColor = Color::Transparent;
					 buttonX10 ->BackColor = Color::Transparent;
					 buttonX100 ->BackColor = Color::Transparent;
				 }
			 }
		 }
private: System::Void buttonX100_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode ==WHEEL_MODE)
			 {
				 if(cncDataPtr->mmiDataPtr->XButtonCheck[2]==false)
				 {
					 cncDataPtr->mmiDataPtr->XButtonCheck[0]=false;
					 cncDataPtr->mmiDataPtr->XButtonCheck[1]=false;
					 cncDataPtr->mmiDataPtr->XButtonCheck[2]=true;
					 cncDataPtr->mmiDataPtr->formInput = true;
					 cncDataPtr->mmiDataPtr->wheelRatio =0.1;
					 buttonX1 ->BackColor = Color::Transparent;
					 buttonX10 ->BackColor = Color::Transparent;
					 buttonX100 ->BackColor = Color::LimeGreen;
				 }
				 else
				 {
					 cncDataPtr->mmiDataPtr->XButtonCheck[0]=false;
					 cncDataPtr->mmiDataPtr->XButtonCheck[1]=false;
					 cncDataPtr->mmiDataPtr->XButtonCheck[2]=false;
					 buttonX1 ->BackColor = Color::Transparent;
					 buttonX10 ->BackColor = Color::Transparent;
					 buttonX100 ->BackColor = Color::Transparent;
				 }
			 }
		 }
private: System::Void buttonStart_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(cncDataPtr->mmiDataPtr->startValid == false)
			 {
				 cncDataPtr->mmiDataPtr->startButton = true;
				 cncDataPtr->mmiDataPtr->startValid = true;
				 cncDataPtr->mmiDataPtr->formInput = true;
			 }

		 }
private: System::Void buttonReset_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->resetValid == false)
			 {
				 cncDataPtr->mmiDataPtr->resetButton = true;
				 cncDataPtr->mmiDataPtr->resetValid = true;
				 cncDataPtr->mmiDataPtr->formInput = true;

				 buttonXPlus ->BackColor = Color::Transparent;
				 buttonXMinus ->BackColor = Color::Transparent;
				 buttonYPlus ->BackColor = Color::Transparent;
				 buttonYMinus ->BackColor = Color::Transparent;
				 buttonZPlus ->BackColor = Color::Transparent;
				 buttonZMinus ->BackColor = Color::Transparent;
				 buttonX1 ->BackColor = Color::Transparent;
				 buttonX10 ->BackColor = Color::Transparent;
				 buttonX100 ->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;	 
				 cncDataPtr->mmiDataPtr->XButtonCheck[0]=false;
				 cncDataPtr->mmiDataPtr->XButtonCheck[1]=false;
				 cncDataPtr->mmiDataPtr->XButtonCheck[2]=false;
			 }
		 }
private: System::Void buttonTeachStart_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->teachStartValid == false)
			 {
				 cncDataPtr->mmiDataPtr->teachStartButton = true;
				 cncDataPtr->mmiDataPtr->teachStartValid = true;
				 cncDataPtr->mmiDataPtr->formInput = true;

			 }
		 }
private: System::Void buttonRecord_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->recordValid == false)
			 {
				 cncDataPtr->mmiDataPtr->recordButton = true;
				 cncDataPtr->mmiDataPtr->recordValid = true;
				 cncDataPtr->mmiDataPtr->formInput = true;

			 }
		 }
private: System::Void buttonTeachEnd_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->teachEndValid == false)
			 {
				 cncDataPtr->mmiDataPtr->teachEndButton = true;
				 cncDataPtr->mmiDataPtr->teachEndValid = true;
				 cncDataPtr->mmiDataPtr->formInput = true;

			 }
		 }
private: System::Void buttonEmergencyStop_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->emergencyStopValid == false)
			 {
				 cncDataPtr->mmiDataPtr->emergencyStopButton = true;
				 cncDataPtr->mmiDataPtr->emergencyStopValid = true;
				 cncDataPtr->mmiDataPtr->formInput = true;

			 }
		 }

private: System::Void buttonXPlus_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {			
			if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			{
				cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
				cncDataPtr->mmiDataPtr->axisPlusButton[0] = true;
				cncDataPtr->mmiDataPtr->axisPlusValid[0] = true;
				buttonXPlus ->BackColor = Color::LimeGreen;
				cncDataPtr->mmiDataPtr->formInput = true;
				buttonXMinus->Enabled = false;
				buttonYPlus->Enabled = false;
				buttonYMinus->Enabled = false;
				buttonZPlus->Enabled = false;
				buttonZMinus->Enabled = false;
			
			}


		}
private: System::Void buttonXPlus_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {		 
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			 {
				 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
				 cncDataPtr->mmiDataPtr->axisPlusButton[0] = false;
				 cncDataPtr->mmiDataPtr->axisPlusValid[0] = true;
				 buttonXPlus->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->formInput = true;

				 buttonXMinus->Enabled = true;
				 buttonYPlus->Enabled  = true;
				 buttonYMinus->Enabled = true;
				 buttonZPlus->Enabled  = true;
				 buttonZMinus->Enabled = true;
			 }
		 }



private: System::Void buttonXMinus_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			 {
				 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
				 cncDataPtr->mmiDataPtr->axisMinusButton[0] = true;
				 cncDataPtr->mmiDataPtr->axisMinusValid[0] = true;
				 buttonXMinus ->BackColor = Color::LimeGreen;
				 cncDataPtr->mmiDataPtr->formInput = true;
				 buttonXPlus->Enabled = false;
				 buttonYPlus->Enabled = false;
				 buttonYMinus->Enabled = false;
				 buttonZPlus->Enabled = false;
				 buttonZMinus->Enabled = false;
			 
			 }
		 }
private: System::Void buttonXMinus_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			 {
				 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
				 cncDataPtr->mmiDataPtr->axisMinusButton[0] = false;
				 cncDataPtr->mmiDataPtr->axisMinusValid[0] = true;
				 buttonXMinus->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->formInput = true;

				 buttonXPlus->Enabled = true;
				 buttonYPlus->Enabled = true;
				 buttonYMinus->Enabled = true;
				 buttonZPlus->Enabled = true;
				 buttonZMinus->Enabled = true;
			 }
		 }
private: System::Void buttonYPlus_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			 {	
				 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
				 cncDataPtr->mmiDataPtr->axisPlusButton[1] = true;
				 cncDataPtr->mmiDataPtr->axisPlusValid[1] = true;
				 buttonYPlus ->BackColor = Color::LimeGreen;
				 cncDataPtr->mmiDataPtr->formInput = true;

				 buttonXPlus->Enabled = false;
				 buttonXMinus->Enabled = false;
				 buttonYMinus->Enabled = false;
				 buttonZPlus->Enabled = false;
				 buttonZMinus->Enabled = false;
			 }
		 }
private: System::Void buttonYPlus_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			 {
				 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
				 cncDataPtr->mmiDataPtr->axisPlusButton[1] = false;
				 cncDataPtr->mmiDataPtr->axisPlusValid[1] = true;
				 buttonYPlus->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->formInput = true;

				 buttonXPlus->Enabled = true;
				 buttonXMinus->Enabled = true;
				 buttonYMinus->Enabled = true;
				 buttonZPlus->Enabled = true;
				 buttonZMinus->Enabled = true;
			 }
		 }
private: System::Void buttonYMinus_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			 {
				 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
				 cncDataPtr->mmiDataPtr->axisMinusButton[1] = true;
				 cncDataPtr->mmiDataPtr->axisMinusValid[1] = true;
				 buttonYMinus ->BackColor = Color::LimeGreen;
				 cncDataPtr->mmiDataPtr->formInput = true;

				 buttonXPlus->Enabled = false;
				 buttonXMinus->Enabled = false;
				 buttonYPlus->Enabled = false;
				 buttonZPlus->Enabled = false;
				 buttonZMinus->Enabled = false;
			 }
		 }
private: System::Void buttonYMinus_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			 {
				 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
				 cncDataPtr->mmiDataPtr->axisMinusButton[1] = false;
				 cncDataPtr->mmiDataPtr->axisMinusValid[1] = true;
				 buttonYMinus->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->formInput = true;

				 buttonXPlus->Enabled = true;
				 buttonXMinus->Enabled = true;
				 buttonYPlus->Enabled = true;
				 buttonZPlus->Enabled = true;
				 buttonZMinus->Enabled = true;
			 }
		 }
private: System::Void buttonZPlus_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			 {
				 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
				 cncDataPtr->mmiDataPtr->axisPlusButton[2] = true;
				 cncDataPtr->mmiDataPtr->axisPlusValid[2] = true;
				 buttonZPlus ->BackColor = Color::LimeGreen;
				 cncDataPtr->mmiDataPtr->formInput = true;

				 buttonXPlus->Enabled = false;
				 buttonXMinus->Enabled = false;
				 buttonYPlus->Enabled = false;
				 buttonYMinus->Enabled = false;
				 buttonZMinus->Enabled = false;
			 }
		 }
private: System::Void buttonZPlus_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			 {
				 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
				 cncDataPtr->mmiDataPtr->axisPlusButton[2] = false;
				 cncDataPtr->mmiDataPtr->axisPlusValid[2] = true;
				 buttonZPlus->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->formInput = true;

				 buttonXPlus->Enabled = true;
				 buttonXMinus->Enabled= true;
				 buttonYPlus->Enabled = true;
				 buttonYMinus->Enabled = true;
				 buttonZMinus->Enabled = true;
			 }
		 }
private: System::Void buttonZMinus_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			 {
				 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
				 cncDataPtr->mmiDataPtr->axisMinusButton[2] = true;
				 cncDataPtr->mmiDataPtr->axisMinusValid[2] = true;
				 buttonZMinus ->BackColor = Color::LimeGreen;
				 cncDataPtr->mmiDataPtr->formInput = true;

				 buttonXPlus->Enabled = false;
				 buttonXMinus->Enabled = false;
				 buttonYPlus->Enabled = false;
				 buttonYMinus->Enabled = false;
				 buttonZPlus->Enabled = false;
			 }
		 }
private: System::Void buttonZMinus_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			 {
				 cncDataPtr->mmiDataPtr->linkDataPtr->opMode = JOG_MODE;
				 cncDataPtr->mmiDataPtr->axisMinusButton[2] = false;
				 cncDataPtr->mmiDataPtr->axisMinusValid[2] = true;
				 buttonZMinus->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->formInput = true;

				 buttonXPlus->Enabled = true;
				 buttonXMinus->Enabled = true;
				 buttonYPlus->Enabled = true;
				 buttonYMinus->Enabled = true;
				 buttonZPlus->Enabled = true;
			 }
		 }


private: System::Void buttonXPlus_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode == WHEEL_MODE)
			 {
				 if(cncDataPtr->mmiDataPtr->XYZButtonCheck[0]==false)
				 {
				 cncDataPtr->mmiDataPtr->axis = XPLUS;
				 cncDataPtr->mmiDataPtr->formInput = true;
				 buttonXPlus ->BackColor = Color::LimeGreen;
				 buttonXMinus ->BackColor = Color::Transparent;
				 buttonYPlus ->BackColor = Color::Transparent;
				 buttonYMinus ->BackColor = Color::Transparent;
				 buttonZPlus ->BackColor = Color::Transparent;
				 buttonZMinus ->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=true;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;
				 }
				 else
				 {
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;
					 buttonXPlus ->BackColor = Color::Transparent;
					 buttonXMinus ->BackColor = Color::Transparent;
					 buttonYPlus ->BackColor = Color::Transparent;
					 buttonYMinus ->BackColor = Color::Transparent;
					 buttonZPlus ->BackColor = Color::Transparent;
					 buttonZMinus ->BackColor = Color::Transparent;
				 }
			 }
			 else
			 {

			 }
		 }
private: System::Void buttonXMinus_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode == WHEEL_MODE)
			 {
				 if(cncDataPtr->mmiDataPtr->XYZButtonCheck[1]==false)
				 {
				 cncDataPtr->mmiDataPtr->axis = XMINUS;
				 cncDataPtr->mmiDataPtr->formInput = true;
				 buttonXMinus ->BackColor = Color::LimeGreen;
				 buttonXPlus ->BackColor = Color::Transparent;
				 buttonYPlus ->BackColor = Color::Transparent;
				 buttonYMinus ->BackColor = Color::Transparent;
				 buttonZPlus ->BackColor = Color::Transparent;
				 buttonZMinus ->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=true;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;
				 }
				 else
				 {
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;
					 buttonXPlus ->BackColor = Color::Transparent;
					 buttonXMinus ->BackColor = Color::Transparent;
					 buttonYPlus ->BackColor = Color::Transparent;
					 buttonYMinus ->BackColor = Color::Transparent;
					 buttonZPlus ->BackColor = Color::Transparent;
					 buttonZMinus ->BackColor = Color::Transparent;
				 }
			 }
			 else
			 {

			 }
		 }
private: System::Void buttonYPlus_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode == WHEEL_MODE)
			 {
				 if(cncDataPtr->mmiDataPtr->XYZButtonCheck[2]==false)
				 {
				 cncDataPtr->mmiDataPtr->axis = YPLUS;
				 cncDataPtr->mmiDataPtr->formInput = true;
				 buttonYPlus ->BackColor = Color::LimeGreen;
				 buttonXPlus ->BackColor = Color::Transparent;
				 buttonXMinus ->BackColor = Color::Transparent;
				 buttonYMinus ->BackColor = Color::Transparent;
				 buttonZPlus ->BackColor = Color::Transparent;
				 buttonZMinus ->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=true;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;
				 }
				 else
				 {
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;
					 buttonXPlus ->BackColor = Color::Transparent;
					 buttonXMinus ->BackColor = Color::Transparent;
					 buttonYPlus ->BackColor = Color::Transparent;
					 buttonYMinus ->BackColor = Color::Transparent;
					 buttonZPlus ->BackColor = Color::Transparent;
					 buttonZMinus ->BackColor = Color::Transparent;
				 }
			 }
			 else
			 {

			 }
		 }
private: System::Void buttonYMinus_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode == WHEEL_MODE)
			 {
				 if(cncDataPtr->mmiDataPtr->XYZButtonCheck[3]==false)
				 {
				 cncDataPtr->mmiDataPtr->axis = YMINUS;
				 cncDataPtr->mmiDataPtr->formInput = true;
				 buttonYMinus ->BackColor = Color::LimeGreen;
				 buttonXPlus ->BackColor = Color::Transparent;
				 buttonXMinus ->BackColor = Color::Transparent;
				 buttonYPlus ->BackColor = Color::Transparent;
				 buttonZPlus ->BackColor = Color::Transparent;
				 buttonZMinus ->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=true;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;
				 }
				 else
				 {
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;
					 buttonXPlus ->BackColor = Color::Transparent;
					 buttonXMinus ->BackColor = Color::Transparent;
					 buttonYPlus ->BackColor = Color::Transparent;
					 buttonYMinus ->BackColor = Color::Transparent;
					 buttonZPlus ->BackColor = Color::Transparent;
					 buttonZMinus ->BackColor = Color::Transparent;
				 }
			 }
			 else
			 {

			 }
		 }
private: System::Void buttonZPlus_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode == WHEEL_MODE)
			 {
				 if(cncDataPtr->mmiDataPtr->XYZButtonCheck[4]==false)
				 {
				 cncDataPtr->mmiDataPtr->axis = ZPLUS;
				 cncDataPtr->mmiDataPtr->formInput = true;
				 buttonZPlus ->BackColor = Color::LimeGreen;
				 buttonXPlus ->BackColor = Color::Transparent;
				 buttonXMinus ->BackColor = Color::Transparent;
				 buttonYPlus ->BackColor = Color::Transparent;
				 buttonYMinus ->BackColor = Color::Transparent;
				 buttonZMinus ->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=true;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;				 
				 }
				 else
				 {
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;
					 buttonXPlus ->BackColor = Color::Transparent;
					 buttonXMinus ->BackColor = Color::Transparent;
					 buttonYPlus ->BackColor = Color::Transparent;
					 buttonYMinus ->BackColor = Color::Transparent;
					 buttonZPlus ->BackColor = Color::Transparent;
					 buttonZMinus ->BackColor = Color::Transparent;
				 }
			 }
			 else
			 {

			 }
		 }
private: System::Void buttonZMinus_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode == WHEEL_MODE)
			 {
				 if(cncDataPtr->mmiDataPtr->XYZButtonCheck[5]==false)
				 {
				 cncDataPtr->mmiDataPtr->axis = ZMINUS;
				 cncDataPtr->mmiDataPtr->formInput = true;
				 buttonZMinus ->BackColor = Color::LimeGreen;
				 buttonXPlus ->BackColor = Color::Transparent;
				 buttonXMinus ->BackColor = Color::Transparent;
				 buttonYPlus ->BackColor = Color::Transparent;
				 buttonYMinus ->BackColor = Color::Transparent;
				 buttonZPlus ->BackColor = Color::Transparent;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=true;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
				 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;			 
				 }
				 else
				 {
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;
					 buttonXPlus ->BackColor = Color::Transparent;
					 buttonXMinus ->BackColor = Color::Transparent;
					 buttonYPlus ->BackColor = Color::Transparent;
					 buttonYMinus ->BackColor = Color::Transparent;
					 buttonZPlus ->BackColor = Color::Transparent;
					 buttonZMinus ->BackColor = Color::Transparent;
				 }
			 }
			 else
			 {

			 }
		 }
private: System::Void timerNonreal_Tick(System::Object^  sender, System::EventArgs^  e) {

			 cncNRTCtl(cncDataPtr);

			 cncDataPtr->sysDataPtr->xyzNew[0] = cncDataPtr->intpDataPtr->xyzNew[0];
			 cncDataPtr->sysDataPtr->xyzNew[1] = cncDataPtr->intpDataPtr->xyzNew[1];
			 cncDataPtr->sysDataPtr->xyzNew[2] = cncDataPtr->intpDataPtr->xyzNew[2];

			 cncDataPtr->sysDataPtr->uvwNew[0] = cncDataPtr->intpDataPtr->uvwNew[0];
			 cncDataPtr->sysDataPtr->uvwNew[1] = cncDataPtr->intpDataPtr->uvwNew[1];
			 cncDataPtr->sysDataPtr->uvwNew[2] = cncDataPtr->intpDataPtr->uvwNew[2];

			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode == NULL_MODE)
			 {
				 buttonMEM->BackColor = Color::Silver;
				 buttonMDI->BackColor = Color::Silver;
				 buttonJOG->BackColor = Color::Silver;
				 buttonWHEEL->BackColor = Color::Silver;
				 buttonTEACH->BackColor = Color::Silver;
				 buttonHOME->BackColor = Color::Silver;
			 }

			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode == JOG_MODE)
			 {
				 buttonMEM->BackColor = Color::Silver;
				 buttonMDI->BackColor = Color::Silver;
				 buttonJOG->BackColor = Color::SteelBlue;
				 buttonWHEEL->BackColor = Color::Silver;
				 buttonTEACH->BackColor = Color::Silver;
				 buttonHOME->BackColor = Color::Silver;
			 }

			 if(cncDataPtr->linkDataPtr->M30ProgramEnd == true  || cncDataPtr->linkDataPtr->resetOrder.reseting == true) 
			 {
				 labelM30->BackColor = Color::Red;
				 labelPGM->BackColor = Color::Transparent;
			 }
			 else
			 {
				 labelM30->BackColor = Color::Transparent;
				 labelPGM->BackColor = Color::Red;
			 }

			 if(cncDataPtr->linkDataPtr->M00Program== true) 
			 {
				 labelM00->BackColor = Color::Red;
			 }
			 else
			 {
				 labelM00->BackColor = Color::Transparent;
			 }


			 if(cncDataPtr->mmiDataPtr->linkDataPtr->resetOrder.reseting == true)
			 {
				 richTextBoxFilePath->Text = "";
				 richTextBoxNC->Text = "";

			 }

			 if(cncDataPtr->mmiDataPtr->linkDataPtr->opMode != WHEEL_MODE)
			 {

					 buttonXPlus ->BackColor = Color::Transparent;
					 buttonXMinus ->BackColor = Color::Transparent;
					 buttonYPlus ->BackColor = Color::Transparent;
					 buttonYMinus ->BackColor = Color::Transparent;
					 buttonZPlus ->BackColor = Color::Transparent;
					 buttonZMinus ->BackColor = Color::Transparent;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[0]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[1]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[2]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[3]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[4]=false;
					 cncDataPtr->mmiDataPtr->XYZButtonCheck[5]=false;	 
			 }

		 }

private: System::Void timerReal_Tick(System::Object^  sender, System::EventArgs^  e) {
			 
			 labelX->Text = cncDataPtr->intpDataPtr->xyzNew[0].ToString("00.000");
			 labelY->Text = cncDataPtr->intpDataPtr->xyzNew[1].ToString("00.000");
			 labelZ->Text = cncDataPtr->intpDataPtr->xyzNew[2].ToString("00.000");

			 labelU->Text = cncDataPtr->intpDataPtr->uvwNew[0].ToString("00.000");
			 labelV->Text = cncDataPtr->intpDataPtr->uvwNew[1].ToString("00.000");
			 labelW->Text = cncDataPtr->intpDataPtr->uvwNew[2].ToString("00.000");

			 cncDataPtr->mmiDataPtr->counter++;
			 labelYear->Text = cncDataPtr->mmiDataPtr-> counter.ToString("0.00");

			 if(cncDataPtr->mmiDataPtr->counter >1000)
			 {cncDataPtr->mmiDataPtr->counter = 0;}


			 this->chart1->Series["feedrate"]->Points->AddY( cncDataPtr->linkDataPtr->vbMomt);

			 if(cncDataPtr->mmiDataPtr->counter >300)
			 {
				 cncDataPtr->chart1bool = true;
			 }

			 if(cncDataPtr->chart1bool == true)
			 {
				 this->chart1->Series["feedrate"]->Points->RemoveAt(0);
			 }

			 this->chart2->Series["location"]->Points->AddXY( cncDataPtr->intpDataPtr->zero[0],cncDataPtr->intpDataPtr->zero[1]);

			 if(cncDataPtr->mmiDataPtr->counter >2)
			 {
				 cncDataPtr->chart2bool1 = true;
			 }

			 if(cncDataPtr->chart2bool1 == true)
			 {
				 this->chart2->Series["location"]->Points->RemoveAt(0);
			 }

			 this->chart2->Series["location"]->Points->AddXY( cncDataPtr->intpDataPtr->point1[0],cncDataPtr->intpDataPtr->point1[1]);


			 if(cncDataPtr->mmiDataPtr->counter >2)
			 {
				 cncDataPtr->chart2bool2 = true;
			 }

			 if(cncDataPtr->chart2bool2 == true)
			 {
				 this->chart2->Series["location"]->Points->RemoveAt(0);
			 }




			 this->chart2->Series["location2"]->Points->AddXY( cncDataPtr->intpDataPtr->point1[0],cncDataPtr->intpDataPtr->point1[1]);

			 if(cncDataPtr->mmiDataPtr->counter >2)
			 {
				 cncDataPtr->chart2bool3 = true;
			 }

			 if(cncDataPtr->chart2bool3 == true)
			 {
				 this->chart2->Series["location2"]->Points->RemoveAt(0);
			 }

			 this->chart2->Series["location2"]->Points->AddXY( cncDataPtr->intpDataPtr->xyzNew[0],cncDataPtr->intpDataPtr->xyzNew[1]);		


			 if(cncDataPtr->mmiDataPtr->counter >2)
			 {
				 cncDataPtr->chart2bool4 = true;
			 }

			 if(cncDataPtr->chart2bool4 == true)
			 {
				 this->chart2->Series["location2"]->Points->RemoveAt(0);
			 }

			 this->chart2->Series["location3"]->Points->AddXY( cncDataPtr->intpDataPtr->xyzNew[0],cncDataPtr->intpDataPtr->xyzNew[1]);		


			 if(cncDataPtr->mmiDataPtr->counter >2000)
			 {
				 cncDataPtr->chart2bool5 = true;
			 }

			 if(cncDataPtr->chart2bool5 == true)
			 {
				 this->chart2->Series["location3"]->Points->RemoveAt(0);
			 }


			 labelUPulse->Text = int(cncDataPtr->intpDataPtr->increment[0]  / 0.0018).ToString("00.000");
			 labelVPulse->Text = int(cncDataPtr->intpDataPtr->increment[1]  /0.0018 ).ToString("00.000");
			 labelWPulse->Text = int(cncDataPtr->intpDataPtr->increment[2]  / 0.0025).ToString("00.000");







#if HD_TIMER
#else
			 cncRTCtl(cncDataPtr);
#endif

		 }//timerReal_Tick

private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

			 // close motion card and card timer
#if HD_TIMER
			 disableHDTimer();
			 closeMotionCard();
#endif
		 }
private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {

			 this->chart2->Series["location3"]->Points->Clear();
		 }
};
}

