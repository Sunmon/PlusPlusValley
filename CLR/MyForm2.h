#pragma once
#include "Player.h"
#include "Tile.h"
#include "MyForm1.h"
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
	/// MyForm2에 대한 요약입니다.
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:


		Controller* c = Controller::getInstance();
		//static Controller* c;
		//MyForm2(Controller* c)
		MyForm2()
		{
			//this->c = c;
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ pnl_watermelon;
	private: System::Windows::Forms::Panel^ pnl_random;


	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Panel^ pnl_strawberry;

	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Panel^ pnl_colly;


	protected:

	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pnl_colly = (gcnew System::Windows::Forms::Panel());
			this->pnl_strawberry = (gcnew System::Windows::Forms::Panel());
			this->pnl_random = (gcnew System::Windows::Forms::Panel());
			this->pnl_watermelon = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(1, 2);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(454, 312);
			this->panel1->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->Controls->Add(this->panel11);
			this->panel4->Controls->Add(this->panel10);
			this->panel4->Controls->Add(this->panel8);
			this->panel4->Controls->Add(this->panel7);
			this->panel4->Location = System::Drawing::Point(182, 171);
			this->panel4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(179, 58);
			this->panel4->TabIndex = 2;
			// 
			// panel11
			// 
			this->panel11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel11.BackgroundImage")));
			this->panel11->Location = System::Drawing::Point(41, 2);
			this->panel11->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(19, 20);
			this->panel11->TabIndex = 2;
			this->panel11->Visible = false;
			// 
			// panel10
			// 
			this->panel10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel10.BackgroundImage")));
			this->panel10->Location = System::Drawing::Point(60, 2);
			this->panel10->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(19, 20);
			this->panel10->TabIndex = 2;
			this->panel10->Visible = false;
			// 
			// panel8
			// 
			this->panel8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel8.BackgroundImage")));
			this->panel8->Location = System::Drawing::Point(22, 2);
			this->panel8->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(19, 20);
			this->panel8->TabIndex = 1;
			this->panel8->Visible = false;
			// 
			// panel7
			// 
			this->panel7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel7.BackgroundImage")));
			this->panel7->Location = System::Drawing::Point(2, 2);
			this->panel7->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(16, 20);
			this->panel7->TabIndex = 0;
			this->panel7->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"돋움체", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(25, 26);
			this->button1->TabIndex = 1;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm2::Button1_MouseClick);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Transparent;
			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
			this->panel3->Location = System::Drawing::Point(86, 171);
			this->panel3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(82, 22);
			this->panel3->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->Controls->Add(this->pnl_colly);
			this->panel2->Controls->Add(this->pnl_strawberry);
			this->panel2->Controls->Add(this->pnl_random);
			this->panel2->Controls->Add(this->pnl_watermelon);
			this->panel2->Location = System::Drawing::Point(86, 47);
			this->panel2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(274, 127);
			this->panel2->TabIndex = 0;
			// 
			// pnl_colly
			// 
			this->pnl_colly->BackColor = System::Drawing::Color::Transparent;
			this->pnl_colly->Location = System::Drawing::Point(2, 65);
			this->pnl_colly->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pnl_colly->Name = L"pnl_colly";
			this->pnl_colly->Size = System::Drawing::Size(184, 21);
			this->pnl_colly->TabIndex = 2;
			this->pnl_colly->DoubleClick += gcnew System::EventHandler(this, &MyForm2::Panel12_DoubleClick);
			// 
			// pnl_strawberry
			// 
			this->pnl_strawberry->BackColor = System::Drawing::Color::Transparent;
			this->pnl_strawberry->Location = System::Drawing::Point(2, 99);
			this->pnl_strawberry->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pnl_strawberry->Name = L"pnl_strawberry";
			this->pnl_strawberry->Size = System::Drawing::Size(184, 19);
			this->pnl_strawberry->TabIndex = 1;
			this->pnl_strawberry->DoubleClick += gcnew System::EventHandler(this, &MyForm2::Panel9_DoubleClick);
			// 
			// pnl_random
			// 
			this->pnl_random->BackColor = System::Drawing::Color::Transparent;
			this->pnl_random->Location = System::Drawing::Point(2, 40);
			this->pnl_random->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pnl_random->Name = L"pnl_random";
			this->pnl_random->Size = System::Drawing::Size(184, 20);
			this->pnl_random->TabIndex = 0;
			this->pnl_random->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm2::Panel6_MouseDoubleClick);
			// 
			// pnl_watermelon
			// 
			this->pnl_watermelon->BackColor = System::Drawing::Color::Transparent;
			this->pnl_watermelon->Location = System::Drawing::Point(2, 2);
			this->pnl_watermelon->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pnl_watermelon->Name = L"pnl_watermelon";
			this->pnl_watermelon->Size = System::Drawing::Size(184, 24);
			this->pnl_watermelon->TabIndex = 0;
			this->pnl_watermelon->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm2::Panel5_MouseDoubleClick);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(486, 340);
			this->Controls->Add(this->panel1);
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	

	private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void Button1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	delete this;
}
private: System::Void Panel5_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	/*Item* i = c->getItem();
	i->setItem(panel5);
	Inventory* p = c->getInventory();
	p->addItem(panel5);*/

	Item* item = c->getPlayer()->getStore()->storeInven->findItem("수박씨앗");
	c->getPlayer()->getStore()->buyItem(item, 1);
	panel7->Visible = true;
}
private: System::Void Panel6_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	panel8->Visible = true;
	
	Item* item = c->getPlayer()->getStore()->storeInven->findItem("랜덤씨앗");
	c->getPlayer()->getStore()->buyItem(item,1);

}

private: System::Void Panel9_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
	panel10->Visible = true;
	Item* item = c->getPlayer()->getStore()->storeInven->findItem("딸기씨앗");
	c->getPlayer()->getStore()->buyItem(item, 1);
	
}
private: System::Void Panel12_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
	panel11->Visible = true;
	Item* item = c->getPlayer()->getStore()->storeInven->findItem("배추씨앗");
	c->getPlayer()->getStore()->buyItem(item, 1);
}
};
}
