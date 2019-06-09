#pragma once
#include "Player.h"
#include "Tile.h"
#include "Controller.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include <vcclr.h>
#include <stdlib.h>
#include <WinUser.h>

namespace CLRFInal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// MyForm1�� ���� ����Դϴ�.
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:


		static Controller* c;
		MyForm1(Controller *c)
		{
			this->c = c;
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Button^ button1;





	protected:




	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->panel9);
			this->panel1->Controls->Add(this->panel10);
			this->panel1->Controls->Add(this->panel8);
			this->panel1->Controls->Add(this->panel7);
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(500, 300);
			this->panel1->TabIndex = 0;
			// 
			// panel9
			// 
			this->panel9->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel9.BackgroundImage")));
			this->panel9->Controls->Add(this->button1);
			this->panel9->Location = System::Drawing::Point(194, 77);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(132, 16);
			this->panel9->TabIndex = 5;
			this->panel9->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"����ü", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(115, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(17, 16);
			this->button1->TabIndex = 0;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::Button1_Click);
			// 
			// panel10
			// 
			this->panel10->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel10.BackgroundImage")));
			this->panel10->Location = System::Drawing::Point(483, 3);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(17, 20);
			this->panel10->TabIndex = 6;
			this->panel10->Click += gcnew System::EventHandler(this, &MyForm1::Panel10_Click);
			// 
			// panel8
			// 
			this->panel8->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel8.BackgroundImage")));
			this->panel8->Location = System::Drawing::Point(194, 91);
			this->panel8->Margin = System::Windows::Forms::Padding(2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(132, 130);
			this->panel8->TabIndex = 4;
			this->panel8->Visible = false;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Transparent;
			this->panel7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel7.BackgroundImage")));
			this->panel7->Location = System::Drawing::Point(15, 10);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(25, 50);
			this->panel7->TabIndex = 0;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::Transparent;
			this->panel6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel6.BackgroundImage")));
			this->panel6->Location = System::Drawing::Point(12, 139);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(44, 82);
			this->panel6->TabIndex = 3;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Location = System::Drawing::Point(453, 200);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(44, 82);
			this->panel4->TabIndex = 2;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Transparent;
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->Location = System::Drawing::Point(45, 27);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(51, 82);
			this->panel5->TabIndex = 2;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Transparent;
			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
			this->panel3->Location = System::Drawing::Point(101, 218);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(44, 82);
			this->panel3->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->Location = System::Drawing::Point(344, 139);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(80, 127);
			this->panel2->TabIndex = 1;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(510, 316);
			this->Controls->Add(this->panel1);
			this->KeyPreview = true;
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->panel1->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	

private: System::Void KeyDDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	//c->setPlayerPlace((int)(e->KeyCode));
	c->getPlayer()->move((int)(e->KeyCode));
	panel7->Location = System::Drawing::Point(c->getPlayer()->getX(), c->getPlayer()->gety());
}
		 

		



private: System::Void Panel10_Click(System::Object^ sender, System::EventArgs^ e) {
	panel8->Visible = true;
	panel9->Visible = true;
	button1->Visible = true;
}
private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	panel8->Visible = false;
	panel9->Visible = false;
	button1->Visible = false;
}
};
}
