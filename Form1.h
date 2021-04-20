#include "CarSearch.h"
#include <string>

using namespace System;
using namespace std;
using namespace std::chrono;

#pragma once
bool computePrice = true;
bool computeYear = true;
bool computeMiles = true;
bool programStarted = false;

int heapSortTimeLOW = 0;
int heapSortTimeHIGH = 0;
int MergeSortTimeLOW = 0;
int MergeSortTimeHIGH = 0;
int RadixSortTimeLOW = 0;
int RadixSortTimeHIGH = 0;

CarSearch cars;

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ comboBox4;


	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ comboBox6;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label16;


	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(16, 143);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(75, 26);
			this->textBox3->TabIndex = 20;
			this->textBox3->Text = L"0";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(695, 112);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 30);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Compute";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(305, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(549, 34);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Welcome to the Used Car Searching Tool";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(323, 21);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Select a choice for any criteria option(s)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(618, 116);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 21);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Results:";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Price: Low to High", L"Price: High to Low" });
			this->comboBox1->Location = System::Drawing::Point(760, 78);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(156, 26);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->Text = L"Price: Low to High";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(680, 79);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(74, 21);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Sort By:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(12, 118);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 21);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Price :";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(42) {
				L"1980", L"1981", L"1982", L"1983", L"1984", L"1985",
					L"1986", L"1987", L"1988", L"1989", L"1990", L"1991", L"1992", L"1993", L"1994", L"1995", L"1996", L"1997", L"1998", L"1999",
					L"2000", L"2001", L"2002", L"2003", L"2004", L"2005", L"2006", L"2007", L"2008", L"2009", L"2010", L"2011", L"2012", L"2013",
					L"2014", L"2015", L"2016", L"2017", L"2018", L"2019", L"2020", L"2021"
			});
			this->comboBox2->Location = System::Drawing::Point(150, 218);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(78, 28);
			this->comboBox2->TabIndex = 6;
			this->comboBox2->Text = L"2021";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(12, 194);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(57, 21);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Year :";
			// 
			// comboBox3
			// 
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(42) {
				L"1980", L"1981", L"1982", L"1983", L"1984", L"1985",
					L"1986", L"1987", L"1988", L"1989", L"1990", L"1991", L"1992", L"1993", L"1994", L"1995", L"1996", L"1997", L"1998", L"1999",
					L"2000", L"2001", L"2002", L"2003", L"2004", L"2005", L"2006", L"2007", L"2008", L"2009", L"2010", L"2011", L"2012", L"2013",
					L"2014", L"2015", L"2016", L"2017", L"2018", L"2019", L"2020", L"2021"
			});
			this->comboBox3->Location = System::Drawing::Point(16, 218);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(77, 28);
			this->comboBox3->TabIndex = 8;
			this->comboBox3->Text = L"1980";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(12, 363);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(126, 21);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Manufacturer :";
			// 
			// comboBox4
			// 
			this->comboBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(39) {
				L"ALL", L"Aston-Martin", L"Ferrari", L"Alfa-Romeo",
					L"Tesla", L"Porche", L"Saturn", L"Volvo", L"Lincoln", L"Ram", L"Lexus", L"Mitsubishi", L"Acura", L"Honda", L"Nissan", L"Mercury",
					L"Buick", L"GMC", L"Chrysler", L"Kia", L"Mazda", L"Toyota", L"Pontiac", L"Ford", L"Dodge", L"Jeep", L"BMW", L"Subaru", L"Fiat",
					L"Harley-Davidson", L"Volkswagen", L"Chevrolet", L"Land Rover", L"Hyundai", L"Mercedes-Benz", L"Infiniti", L"Jaguar", L"Audi",
					L"Cadillac"
			});
			this->comboBox4->Location = System::Drawing::Point(16, 387);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(156, 28);
			this->comboBox4->TabIndex = 10;
			this->comboBox4->Text = L"ALL";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(12, 441);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(94, 21);
			this->label9->TabIndex = 15;
			this->label9->Text = L"Condition :";
			// 
			// comboBox6
			// 
			this->comboBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"ALL", L"New", L"Like New", L"Excellent", L"Good",
					L"Fair", L"Salvage"
			});
			this->comboBox6->Location = System::Drawing::Point(16, 465);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(156, 28);
			this->comboBox6->TabIndex = 14;
			this->comboBox6->Text = L"ALL";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(110, 219);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(25, 21);
			this->label10->TabIndex = 16;
			this->label10->Text = L"to";
			this->label10->Click += gcnew System::EventHandler(this, &Form1::label10_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(110, 145);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(25, 21);
			this->label11->TabIndex = 18;
			this->label11->Text = L"to";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(150, 143);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(75, 26);
			this->textBox2->TabIndex = 19;
			this->textBox2->Text = L"1000000";
			// 
			// textBox1
			// 
			this->textBox1->AcceptsReturn = true;
			this->textBox1->AcceptsTab = true;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(347, 148);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(904, 410);
			this->textBox1->TabIndex = 21;
			this->textBox1->TabStop = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(466, 566);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(129, 21);
			this->label12->TabIndex = 23;
			this->label12->Text = L"Heapsort Time:";
			this->label12->Click += gcnew System::EventHandler(this, &Form1::label12_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(701, 567);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(135, 21);
			this->label13->TabIndex = 24;
			this->label13->Text = L"Mergesort Time:";
			this->label13->Click += gcnew System::EventHandler(this, &Form1::label13_Click);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(601, 564);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(75, 26);
			this->textBox4->TabIndex = 25;
			this->textBox4->Text = L"0";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(841, 564);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(75, 26);
			this->textBox5->TabIndex = 26;
			this->textBox5->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(110, 302);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(25, 21);
			this->label8->TabIndex = 30;
			this->label8->Text = L"to";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(12, 277);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(62, 21);
			this->label14->TabIndex = 29;
			this->label14->Text = L"Miles :";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(16, 302);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(75, 26);
			this->textBox6->TabIndex = 31;
			this->textBox6->Text = L"0";
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(150, 302);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(75, 26);
			this->textBox7->TabIndex = 32;
			this->textBox7->Text = L"1000000";
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox8->Location = System::Drawing::Point(1088, 564);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(75, 26);
			this->textBox8->TabIndex = 34;
			this->textBox8->Text = L"0";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(948, 567);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(134, 21);
			this->label15->TabIndex = 33;
			this->label15->Text = L"Radixsort Time:";
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(904, 116);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(75, 26);
			this->textBox9->TabIndex = 36;
			this->textBox9->Text = L"0";
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &Form1::textBox9_TextChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(796, 118);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(102, 21);
			this->label16->TabIndex = 35;
			this->label16->Text = L"Cars Found:";
			this->label16->Click += gcnew System::EventHandler(this, &Form1::label16_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1263, 647);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		// check the price range
		String^ plow = textBox3->Text;
		String^ phigh = textBox2->Text;
		double priceLow = System::Convert::ToDouble(plow);
		double priceHigh = System::Convert::ToDouble(phigh);
		if (priceLow >= priceHigh) {
			//price range not correct
			computePrice = false;
			textBox1->Text = "ERROR \n\n Price Range Incorrect!";
		}
		else {
			computePrice = true;
		}

		// check the year range
		String^ ylow = comboBox3->Text;
		String^ yhigh = comboBox2->Text;
		int yearLow = System::Convert::ToInt32(ylow);
		int yearHigh = System::Convert::ToInt32(yhigh);
		if (yearLow >= yearHigh) {
			//year range not correct
			computeYear = false;
			textBox1->Text = "ERROR \n\n Year Range Incorrect!";
		}
		else {
			computeYear = true;
		}

		// check the mile range
		String^ mlow = textBox6->Text;
		String^ mhigh = textBox7->Text;
		int mileLow = System::Convert::ToInt32(mlow);
		int mileHigh = System::Convert::ToInt32(mhigh);
		if (mileLow >= mileHigh) {
			//year range not correct
			computeMiles = false;
			textBox1->Text = "ERROR \n\n Mile Range Incorrect!";
		}
		else {
			computeMiles = true;
		}

		// get the make
		String^ m = comboBox4->Text;
		string make;
		if (m == "ALL") { make = ""; } 
		if (m == "Aston-Martin") { make = "aston-martin"; }
		if (m == "Ferrari") { make = "ferrari"; }
		if (m == "Alfa-Romeo") { make = "alfa-romeo"; }
		if (m == "Tesla") { make = "tesla"; }
		if (m == "Porche") { make = "porche"; }
		if (m == "Saturn") { make = "saturn"; }
		if (m == "Volvo") { make = "volvo"; }
		if (m == "Lincoln") { make = "lincoln"; }
		if (m == "Ram") { make = "ram"; }
		if (m == "Lexus") { make = "lexus"; }
		if (m == "Mitsubishi") { make = "mitsubishi"; }
		if (m == "Acura") { make = "acura"; }
		if (m == "Honda") { make = "honda"; }
		if (m == "Nissan") { make = "nissan"; }
		if (m == "Mercury") { make = "mercury"; }
		if (m == "Buick") { make = "buick"; }
		if (m == "GMC") { make = "gmc"; }
		if (m == "Chrysler") { make = "chrysler"; }
		if (m == "Kia") { make = "kia"; }
		if (m == "Mazda") { make = "mazda"; }
		if (m == "Toyota") { make = "toyota"; }
		if (m == "Pontiac") { make = "pontiac"; }
		if (m == "Ford") { make = "ford"; }
		if (m == "Dodge") { make = "dodge"; }
		if (m == "Jeep") { make = "jeep"; }
		if (m == "BMW") { make = "bmw"; }
		if (m == "Subaru") { make = "subaru"; }
		if (m == "Fiat") { make = "fiat"; }
		if (m == "Harley-Davidson") { make = "harley-davidson"; }
		if (m == "Volkswagen") { make = "volkswagen"; }
		if (m == "Chevrolet") { make = "chevrolet"; }
		if (m == "Land Rover") { make = "land rover"; }
		if (m == "Hyundai") { make = "hyundai"; }
		if (m == "Mercedes-Benz") { make = "mercedes-benz"; }
		if (m == "Infiniti") { make = "infiniti"; }
		if (m == "Jaguar") { make = "jaguar"; }
		if (m == "Audi") { make = "audi"; }
		if (m == "Cadillac") { make = "cadillac"; }

		// get the condition
		String^ c = comboBox6->Text;
		string condition;
		if (c == "ALL") { condition = ""; }
		if (c == "New") { condition = "new"; }
		if (c == "Like New") { condition = "like new"; }
		if (c == "Excellent") { condition = "excellent"; }
		if (c == "Good") { condition = "good"; }
		if (c == "Fair") { condition = "fair"; }
		if (c == "Salvage") { condition = "salvage"; }

		// check compute value
		if ((computePrice == true) && (computeYear == true) && (computeMiles == true)) {

			// ************** BEGIN CAR CODE ************** //
			if (programStarted == false) {
				textBox1->Text = "LOADING DATA...";
				programStarted = true;
				cars.generateData("test.csv");
			}
			cars.Search(priceLow, priceHigh, yearLow, yearHigh, make, "", condition, mileLow, mileHigh);
			
			// print vector
			std::vector<Car*> printOutLOW;
			std::vector<Car*> printOutHIGH;

			vector<Car*> tempVect = cars.getOutput();

			auto start = high_resolution_clock::now();
			printOutLOW = cars.heapSortLowToHigh(cars.getOutput());
			auto end = high_resolution_clock::now();
			auto time = duration_cast<milliseconds>(end - start);
			heapSortTimeLOW = time.count();

			start = high_resolution_clock::now();
			printOutHIGH = cars.heapSortHighToLow(cars.getOutput());
			end = high_resolution_clock::now();
			time = duration_cast<milliseconds>(end - start);
			heapSortTimeHIGH = time.count();

			start = high_resolution_clock::now();
			cars.mergesortLowToHigh(cars.getOutput());
			end = high_resolution_clock::now();
			time = duration_cast<milliseconds>(end - start);
			MergeSortTimeLOW = time.count();

			start = high_resolution_clock::now();
			cars.mergesortHighToLow(cars.getOutput());
			end = high_resolution_clock::now();
			time = duration_cast<milliseconds>(end - start);
			MergeSortTimeHIGH = time.count();

			start = high_resolution_clock::now();
			cars.radixSortLowToHigh(tempVect);
			end = high_resolution_clock::now();
			time = duration_cast<milliseconds>(end - start);
			RadixSortTimeLOW = time.count();

			tempVect = cars.getOutput();

			start = high_resolution_clock::now();
			cars.radixSortHighToLow(tempVect);
			end = high_resolution_clock::now();
			time = duration_cast<milliseconds>(end - start);
			RadixSortTimeHIGH = time.count();
			
			// ************** END CAR CODE ************** //
			

			// figure out which time to use
			String^ sortChoice = comboBox1->Text;

			if (sortChoice == "Price: Low to High") {
				textBox1->Clear();
				textBox1->Text = "RESULTS:";
				textBox1->Visible = false;
				for (int x = 0; x < printOutLOW.size(); x++) {
					Car* temp = printOutLOW[x];
					String^ makeR = gcnew String(temp->make.c_str());
					String^ modelR = gcnew String(temp->model.c_str());
					String^ conditionR = gcnew String(temp->condition.c_str());
					String^ listingURLR = gcnew String(temp->listingURL.c_str());
					textBox1->AppendText("\r\n" + temp->year + ";\t$" + temp->price + ";\t" + makeR + ";\t" + modelR + ";\t" + temp->mileage + "miles;\tcondition: " + conditionR);
					textBox1->AppendText("\r\n" + listingURLR + "\r\n");
				}
				textBox1->AppendText("\r\nEND");
				textBox1->Visible = true;

				// print low to high values
				textBox5->Text = System::Convert::ToString(MergeSortTimeLOW + " ms");
				textBox4->Text = System::Convert::ToString(heapSortTimeLOW + " ms");
				textBox8->Text = System::Convert::ToString(RadixSortTimeLOW + " ms");
			}
			else {
				textBox1->Clear();
				textBox1->Text = "RESULTS:";
				textBox1->Visible = false;
				for (int x = 0; x < printOutHIGH.size(); x++) {
					Car* temp = printOutHIGH[x];
					String^ makeR = gcnew String(temp->make.c_str());
					String^ modelR = gcnew String(temp->model.c_str());
					String^ conditionR = gcnew String(temp->condition.c_str());
					String^ listingURLR = gcnew String(temp->listingURL.c_str());
					textBox1->AppendText("\r\n" + temp->year + ";\t$" + temp->price + ";\t" + makeR + ";\t" + modelR + ";\t" + temp->mileage + "miles;\tcondition: " + conditionR);
					textBox1->AppendText("\r\n" + listingURLR + "\r\n");
				}
				textBox1->AppendText("\r\nEND");
				textBox1->Visible = true;

				// print high to low values
				textBox5->Text = System::Convert::ToString(MergeSortTimeHIGH + " ms");
				textBox4->Text = System::Convert::ToString(heapSortTimeHIGH + " ms");
				textBox8->Text = System::Convert::ToString(RadixSortTimeHIGH + " ms");
			}
			textBox9->Text = System::Convert::ToString(printOutHIGH.size());
		}
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void vScrollBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	}
	private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label15_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label16_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
