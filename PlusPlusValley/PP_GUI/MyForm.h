//#pragma once
//#include "MyForm1.h"
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
//	/// MyForm에 대한 요약입니다.
//	/// </summary>
//	public ref class MyForm : public System::Windows::Forms::Form
//	{
//	public:
//		static Controller* c;
//		MyForm(Controller *c)
//		{ 
//			InitializeComponent();
//			this->c = c;
//			//
//			//TODO: 생성자 코드를 여기에 추가합니다.
//			//
//		}
//
//	protected:
//		/// <summary>
//		/// 사용 중인 모든 리소스를 정리합니다.
//		/// </summary>
//		~MyForm()
//		{
//			if (components)
//			{
//				delete components;
//			}
//		}
//	private: System::Windows::Forms::Panel^ panel1;
//	protected:
//	private: System::Windows::Forms::TextBox^ textBox1;
//	private: System::Windows::Forms::Button^ button1;
//	private: System::Windows::Forms::Label^ label1;
//	private: System::Windows::Forms::MessageBox^ message1;
//	private: System::Windows::Forms::MessageBoxOptions^ messageButton1;
//	private: System::Windows::Forms::GroupBox^ groupBox1;
//	private: System::Windows::Forms::Button^ button2;
//	private: System::Windows::Forms::Button^ button3;
//
//
//	private:
//		/// <summary>
//		/// 필수 디자이너 변수입니다.
//		/// </summary>
//		System::ComponentModel::Container ^components;
//
//#pragma region Windows Form Designer generated code
//		/// <summary>
//		/// 디자이너 지원에 필요한 메서드입니다. 
//		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
//		/// </summary>
//		void InitializeComponent(void)
//		{
//			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
//			this->panel1 = (gcnew System::Windows::Forms::Panel());
//			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
//			this->button2 = (gcnew System::Windows::Forms::Button());
//			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
//			this->button1 = (gcnew System::Windows::Forms::Button());
//			this->label1 = (gcnew System::Windows::Forms::Label());
//			this->button3 = (gcnew System::Windows::Forms::Button());
//			this->panel1->SuspendLayout();
//			this->groupBox1->SuspendLayout();
//			this->SuspendLayout();
//			// 
//			// panel1
//			// 
//			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
//			this->panel1->Controls->Add(this->groupBox1);
//			this->panel1->Controls->Add(this->textBox1);
//			this->panel1->Controls->Add(this->button1);
//			this->panel1->Controls->Add(this->label1);
//			this->panel1->Location = System::Drawing::Point(0, 0);
//			this->panel1->Name = L"panel1";
//			this->panel1->Size = System::Drawing::Size(500, 300);
//			this->panel1->TabIndex = 0;
//			// 
//			// groupBox1
//			// 
//			this->groupBox1->Controls->Add(this->button3);
//			this->groupBox1->Controls->Add(this->button2);
//			this->groupBox1->Location = System::Drawing::Point(157, 117);
//			this->groupBox1->Name = L"groupBox1";
//			this->groupBox1->Size = System::Drawing::Size(200, 100);
//			this->groupBox1->TabIndex = 1;
//			this->groupBox1->TabStop = false;
//			this->groupBox1->Visible = false;
//			// 
//			// button2
//			// 
//			this->button2->Location = System::Drawing::Point(11, 64);
//			this->button2->Name = L"button2";
//			this->button2->Size = System::Drawing::Size(75, 23);
//			this->button2->TabIndex = 1;
//			this->button2->Text = L"확인";
//			this->button2->UseVisualStyleBackColor = true;
//			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
//			// 
//			// textBox1
//			// 
//			this->textBox1->AccessibleRole = System::Windows::Forms::AccessibleRole::Text;
//			this->textBox1->Location = System::Drawing::Point(168, 154);
//			this->textBox1->Name = L"textBox1";
//			this->textBox1->Size = System::Drawing::Size(189, 21);
//			this->textBox1->TabIndex = 2;
//			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox1_TextChanged);
//			// 
//			// button1
//			// 
//			this->button1->BackColor = System::Drawing::Color::Transparent;
//			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
//			this->button1->Location = System::Drawing::Point(381, 154);
//			this->button1->Name = L"button1";
//			this->button1->Size = System::Drawing::Size(75, 23);
//			this->button1->TabIndex = 1;
//			this->button1->Text = L"Start";
//			this->button1->UseVisualStyleBackColor = false;
//			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
//			// 
//			// label1
//			// 
//			this->label1->AutoSize = true;
//			this->label1->BackColor = System::Drawing::Color::Transparent;
//			this->label1->Font = (gcnew System::Drawing::Font(L"굴림체", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(129)));
//			this->label1->ForeColor = System::Drawing::Color::Snow;
//			this->label1->Location = System::Drawing::Point(32, 154);
//			this->label1->Name = L"label1";
//			this->label1->Size = System::Drawing::Size(130, 19);
//			this->label1->TabIndex = 0;
//			this->label1->Text = L"Player Name";
//			this->label1->Click += gcnew System::EventHandler(this, &MyForm::Label1_Click);
//			// 
//			// button3
//			// 
//			this->button3->Location = System::Drawing::Point(104, 64);
//			this->button3->Name = L"button3";
//			this->button3->Size = System::Drawing::Size(75, 23);
//			this->button3->TabIndex = 2;
//			this->button3->Text = L"아니요";
//			this->button3->UseVisualStyleBackColor = true;
//			this->button3->Click += gcnew System::EventHandler(this, &MyForm::Button3_Click);
//			// 
//			// MyForm
//			// 
//			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
//			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//			this->ClientSize = System::Drawing::Size(729, 512);
//			this->Controls->Add(this->panel1);
//			this->Name = L"MyForm";
//			this->Text = L"MyForm";
//			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
//			this->panel1->ResumeLayout(false);
//			this->panel1->PerformLayout();
//			this->groupBox1->ResumeLayout(false);
//			this->ResumeLayout(false);
//
//		}
//
//#pragma endregion
//	
//	private: System::Void TextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
//	}
//	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
//		c->init();
//		c->getPlayer()->setName(msclr::interop::marshal_as<std::string>(textBox1->Text));
//		
//		groupBox1->Show();
//		GroupBox1_Enter(sender, e);
//	}
//
//	
//	
//	
//	private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
//	}
//private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
//}
//private: System::Void TextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
//}
//private: System::Void GroupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
//	groupBox1->Text = ("\n\n캐릭터 이름은 " + marshal_as<String^>(c->getPlayer()->getName()) + "입니다");
//}
//private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
//	delete this;
//}
//private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
//	groupBox1->Hide();
//}
//};
//}
