#pragma once
#include "Player.h"
#include "MyForm1.h"
#include "MyForm2.h"
#include "Tile.h"
#include "Controller.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include <vcclr.h>
#include <stdlib.h>

namespace CLRFInal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// MyForm�� ���� ����Դϴ�.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		static Controller* c;
		MyForm(Controller *c)
		{ 
			InitializeComponent();
			this->c = c;
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MessageBox^ message1;
	private: System::Windows::Forms::MessageBoxOptions^ messageButton1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;


	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(-4, -4);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(714, 450);
			this->panel1->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Location = System::Drawing::Point(224, 176);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(286, 150);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Visible = false;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(149, 96);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(107, 34);
			this->button3->TabIndex = 2;
			this->button3->Text = L"�ƴϿ�";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::Button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(16, 96);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 34);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Ȯ��";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->AccessibleRole = System::Windows::Forms::AccessibleRole::Text;
			this->textBox1->Location = System::Drawing::Point(240, 231);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(268, 28);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(544, 231);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"����ü", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->ForeColor = System::Drawing::Color::Snow;
			this->label1->Location = System::Drawing::Point(46, 231);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(189, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Player Name";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::Label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(723, 459);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}

#pragma endregion
	
	private: System::Void TextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//c->setName(msclr::interop::marshal_as<std::string>(textBox1->Text));
		c->getPlayer()->setName(msclr::interop::marshal_as<std::string>(textBox1->Text));
		
		groupBox1->Show();
		GroupBox1_Enter(sender, e);
	}

	
	
	
	private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void GroupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	//groupBox1->Text = ("\n\nĳ���� �̸��� " + marshal_as<String^>(c->getPlayerName()) + "�Դϴ�");
	groupBox1->Text = ("\n\nĳ���� �̸��� " + marshal_as<String^>(c->getPlayer()->getName()) + "�Դϴ�");
}
private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
	delete this;
}
private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
	groupBox1->Hide();
}
};
}
