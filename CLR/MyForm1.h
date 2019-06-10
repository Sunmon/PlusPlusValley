#pragma once
#include "Player.h"
#include "Tile.h"
#include "MyForm2.h"
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
	/// MyForm1에 대한 요약입니다.
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
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
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


	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Panel^ panel13;
	private: System::Windows::Forms::Panel^ panel12;
	private: System::Windows::Forms::Panel^ panel14;









	protected:




	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->panel14);
			this->panel1->Controls->Add(this->panel9);
			this->panel1->Controls->Add(this->panel8);
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel7);
			this->panel1->Controls->Add(this->panel10);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->panel11);
			this->panel1->Controls->Add(this->panel12);
			this->panel1->Controls->Add(this->panel13);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(714, 450);
			this->panel1->TabIndex = 0;
			// 
			// panel14
			// 
			this->panel14->BackColor = System::Drawing::Color::Transparent;
			this->panel14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel14.BackgroundImage")));
			this->panel14->Location = System::Drawing::Point(516, 81);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(38, 77);
			this->panel14->TabIndex = 7;
			this->panel14->DoubleClick += gcnew System::EventHandler(this, &MyForm1::Panel14_DoubleClick);
			// 
			// panel9
			// 
			this->panel9->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel9.BackgroundImage")));
			this->panel9->Controls->Add(this->button1);
			this->panel9->Location = System::Drawing::Point(277, 116);
			this->panel9->Margin = System::Windows::Forms::Padding(4);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(189, 24);
			this->panel9->TabIndex = 5;
			this->panel9->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"돋움체", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(164, 0);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(24, 24);
			this->button1->TabIndex = 0;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::Button1_Click);
			// 
			// panel8
			// 
			this->panel8->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel8.BackgroundImage")));
			this->panel8->Location = System::Drawing::Point(277, 136);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(189, 195);
			this->panel8->TabIndex = 4;
			this->panel8->Visible = false;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::Transparent;
			this->panel6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel6.BackgroundImage")));
			this->panel6->Location = System::Drawing::Point(17, 208);
			this->panel6->Margin = System::Windows::Forms::Padding(4);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(63, 123);
			this->panel6->TabIndex = 3;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Location = System::Drawing::Point(647, 300);
			this->panel4->Margin = System::Windows::Forms::Padding(4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(63, 123);
			this->panel4->TabIndex = 2;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Transparent;
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->Location = System::Drawing::Point(64, 40);
			this->panel5->Margin = System::Windows::Forms::Padding(4);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(73, 123);
			this->panel5->TabIndex = 2;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Transparent;
			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
			this->panel3->Location = System::Drawing::Point(144, 327);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(63, 123);
			this->panel3->TabIndex = 1;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Transparent;
			this->panel7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel7.BackgroundImage")));
			this->panel7->Location = System::Drawing::Point(21, 15);
			this->panel7->Margin = System::Windows::Forms::Padding(4);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(36, 75);
			this->panel7->TabIndex = 0;
			// 
			// panel10
			// 
			this->panel10->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel10.BackgroundImage")));
			this->panel10->Location = System::Drawing::Point(690, 4);
			this->panel10->Margin = System::Windows::Forms::Padding(4);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(24, 30);
			this->panel10->TabIndex = 6;
			this->panel10->Click += gcnew System::EventHandler(this, &MyForm1::Panel10_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->Location = System::Drawing::Point(491, 208);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(114, 190);
			this->panel2->TabIndex = 1;
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::Color::Transparent;
			this->panel11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel11.BackgroundImage")));
			this->panel11->Location = System::Drawing::Point(88, 263);
			this->panel11->Margin = System::Windows::Forms::Padding(4);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(51, 68);
			this->panel11->TabIndex = 3;
			this->panel11->Visible = false;
			// 
			// panel12
			// 
			this->panel12->BackColor = System::Drawing::Color::Transparent;
			this->panel12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel12.BackgroundImage")));
			this->panel12->Location = System::Drawing::Point(215, 378);
			this->panel12->Margin = System::Windows::Forms::Padding(4);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(51, 68);
			this->panel12->TabIndex = 4;
			this->panel12->Visible = false;
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::Color::Transparent;
			this->panel13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel13.BackgroundImage")));
			this->panel13->Location = System::Drawing::Point(655, 233);
			this->panel13->Margin = System::Windows::Forms::Padding(4);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(51, 68);
			this->panel13->TabIndex = 4;
			this->panel13->Visible = false;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(729, 474);
			this->Controls->Add(this->panel1);
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->panel1->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);

			this->KeyPreview = true;
			this->KeyDown += gcnew KeyEventHandler(this, &MyForm1::KeyDDown);

		}
#pragma endregion
	

private: System::Void KeyDDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	//c->setPlayerPlace((int)(e->KeyCode));
	Player *p = c->getPlayer();
	int k = (int)(e->KeyCode);
	p->move((int)(e->KeyCode));
	panel7->Location = System::Drawing::Point(p->getX(),p->gety());
	int x = p->getX();
	int y = p->gety();

	if(k == 32){
		for (int i = 0; i < 3; i++) {
			MapObject m = c->getMapObject(i);
			int mx = m.getPlace()[0];
			int my = m.getPlace()[1];
			
		

			if (x <= mx + 22 && x >= mx - 22 && y >= my - 41 && y <= my + 41) {
				int h = m.getHealth();
				if (h > 60) {
					h = h - 10;
					m.setHealth(h);
				}
				else {
					if (i == 0) {
						panel6->Visible = false;
						panel11->Visible = true;
					}
					else if (i == 1) {
						panel3->Visible = false;
						panel12->Visible = true;
					}
					else if (i == 2) {
						panel4->Visible = false;
						panel13->Visible = true;
					}
				}
				c->setMapObject(m, i);
				break;
			}
			
		}
	}

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

private: System::Void Panel14_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
	delete this;
}
};
}
