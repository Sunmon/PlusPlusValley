//#pragma once
//#include "Controller.h"
//#include <string>
//#include <msclr\marshal_cppstd.h>
//#include <vcclr.h>
//#include <stdlib.h>
//
//namespace PPGUI {
//
//	using namespace System;
//	using namespace System::ComponentModel;
//	using namespace System::Collections;
//	using namespace System::Windows::Forms;
//	using namespace System::Data;
//	using namespace System::Drawing;
//	using namespace msclr::interop;
//
//	/// <summary>
//	/// MyForm1에 대한 요약입니다.
//	/// </summary>
//	public ref class MyForm1 : public System::Windows::Forms::Form
//	{
//	public:
//		static Controller* c;
//		MyForm1(Controller *c)
//		{
//			this->c = c;
//			InitializeComponent();
//			//
//			//TODO: 생성자 코드를 여기에 추가합니다.
//			//
//		}
//
//	protected:
//		/// <summary>
//		/// 사용 중인 모든 리소스를 정리합니다.
//		/// </summary>
//		~MyForm1()
//		{
//			if (components)
//			{
//				delete components;
//			}
//		}
//	private: System::Windows::Forms::Panel^ panel1;
//	private: System::Windows::Forms::Panel^ panel2;
//	private: System::Windows::Forms::Panel^ panel6;
//	private: System::Windows::Forms::Panel^ panel4;
//	private: System::Windows::Forms::Panel^ panel5;
//	private: System::Windows::Forms::Panel^ panel3;
//	private: System::Windows::Forms::Panel^ panel7;
//
//
//
//
//
//	protected:
//
//
//
//
//	private: System::ComponentModel::IContainer^ components;
//
//	private:
//		/// <summary>
//		/// 필수 디자이너 변수입니다.
//		/// </summary>
//
//
//#pragma region Windows Form Designer generated code
//		/// <summary>
//		/// 디자이너 지원에 필요한 메서드입니다. 
//		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
//		/// </summary>
//		void InitializeComponent(void)
//		{
//			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
//			this->panel1 = (gcnew System::Windows::Forms::Panel());
//			this->panel7 = (gcnew System::Windows::Forms::Panel());
//			this->panel6 = (gcnew System::Windows::Forms::Panel());
//			this->panel4 = (gcnew System::Windows::Forms::Panel());
//			this->panel5 = (gcnew System::Windows::Forms::Panel());
//			this->panel3 = (gcnew System::Windows::Forms::Panel());
//			this->panel2 = (gcnew System::Windows::Forms::Panel());
//			this->panel1->SuspendLayout();
//			this->panel4->SuspendLayout();
//			this->SuspendLayout();
//			// 
//			// panel1
//			// 
//			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
//			this->panel1->Controls->Add(this->panel7);
//			this->panel1->Controls->Add(this->panel6);
//			this->panel1->Controls->Add(this->panel4);
//			this->panel1->Controls->Add(this->panel3);
//			this->panel1->Controls->Add(this->panel2);
//			this->panel1->Location = System::Drawing::Point(0, 0);
//			this->panel1->Name = L"panel1";
//			this->panel1->Size = System::Drawing::Size(500, 300);
//			this->panel1->TabIndex = 0;
//			// 
//			// panel7
//			// 
//			this->panel7->BackColor = System::Drawing::Color::Transparent;
//			this->panel7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel7.BackgroundImage")));
//			this->panel7->Location = System::Drawing::Point(0, 0);
//			this->panel7->Name = L"panel7";
//			this->panel7->Size = System::Drawing::Size(25, 50);
//			this->panel7->TabIndex = 0;
//			this->panel7->Location = System::Drawing::Point(15,10);
//			// 
//			// panel6
//			// 
//			this->panel6->BackColor = System::Drawing::Color::Transparent;
//			this->panel6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel6.BackgroundImage")));
//			this->panel6->Location = System::Drawing::Point(12, 139);
//			this->panel6->Name = L"panel6";
//			this->panel6->Size = System::Drawing::Size(46, 82);
//			this->panel6->TabIndex = 3;
//			// 
//			// panel4
//			// 
//			this->panel4->BackColor = System::Drawing::Color::Transparent;
//			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
//			this->panel4->Controls->Add(this->panel5);
//			this->panel4->Location = System::Drawing::Point(453, 200);
//			this->panel4->Name = L"panel4";
//			this->panel4->Size = System::Drawing::Size(44, 82);
//			this->panel4->TabIndex = 2;
//			// 
//			// panel5
//			// 
//			this->panel5->BackColor = System::Drawing::Color::Transparent;
//			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
//			this->panel5->Location = System::Drawing::Point(45, 27);
//			this->panel5->Name = L"panel5";
//			this->panel5->Size = System::Drawing::Size(51, 82);
//			this->panel5->TabIndex = 2;
//			// 
//			// panel3
//			// 
//			this->panel3->BackColor = System::Drawing::Color::Transparent;
//			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
//			this->panel3->Location = System::Drawing::Point(101, 218);
//			this->panel3->Name = L"panel3";
//			this->panel3->Size = System::Drawing::Size(51, 82);
//			this->panel3->TabIndex = 1;
//			// 
//			// panel2
//			// 
//			this->panel2->BackColor = System::Drawing::Color::Transparent;
//			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
//			this->panel2->Location = System::Drawing::Point(344, 139);
//			this->panel2->Name = L"panel2";
//			this->panel2->Size = System::Drawing::Size(82, 127);
//			this->panel2->TabIndex = 1;
//			// 
//			// MyForm1
//			// 
//			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
//			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//			this->ClientSize = System::Drawing::Size(685, 396);
//			this->Controls->Add(this->panel1);
//			this->KeyPreview = true;
//			this->Name = L"MyForm1";
//			this->Text = L"MyForm1";
//			this->panel1->ResumeLayout(false);
//			this->panel4->ResumeLayout(false);
//			this->ResumeLayout(false);
//			this->KeyPreview = true;
//			this->KeyDown += gcnew KeyEventHandler(this, &MyForm1::KeyDDown);
//		
//
//		}
//#pragma endregion
//	
//
//private: System::Void KeyDDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
//	
//	//TODO: keyCode 고치기
//	c->getPlayer()->move((int)e->KeyCode);
//	panel7->Location = System::Drawing::Point(c->getPlayer()->getX(), c->getPlayer()->gety());
//
//}
//		 
//
//
//};
//}
