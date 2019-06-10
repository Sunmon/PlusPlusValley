#pragma once
#include "Controller.h"
#include <msclr\marshal_cppstd.h>
#include <string>
#include <msclr\marshal_cppstd.h>
namespace CLRFInal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// startingPage에 대한 요약입니다.
	/// </summary>
	public ref class startingPage : public System::Windows::Forms::Form
	{
	public:
		bool isCharacterSet = false;	//이름 정하고 OK버튼 누르면 true;
		static Controller* controller = Controller::getInstance();
		startingPage(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~startingPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ backgroundPanel;
	private: System::Windows::Forms::Button^ startButton;
	private: System::Windows::Forms::TextBox^ nameTextBox;
	private: System::Windows::Forms::GroupBox^ groubBox;
	private: System::Windows::Forms::Button^ btn_NO;
	private: System::Windows::Forms::Button^ btn_OK;
	private: System::Windows::Forms::Label^ lab_message;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(startingPage::typeid));
			this->backgroundPanel = (gcnew System::Windows::Forms::Panel());
			this->groubBox = (gcnew System::Windows::Forms::GroupBox());
			this->lab_message = (gcnew System::Windows::Forms::Label());
			this->btn_NO = (gcnew System::Windows::Forms::Button());
			this->btn_OK = (gcnew System::Windows::Forms::Button());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->backgroundPanel->SuspendLayout();
			this->groubBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// backgroundPanel
			// 
			this->backgroundPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backgroundPanel.BackgroundImage")));
			this->backgroundPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->backgroundPanel->Controls->Add(this->groubBox);
			this->backgroundPanel->Controls->Add(this->startButton);
			this->backgroundPanel->Controls->Add(this->nameTextBox);
			this->backgroundPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->backgroundPanel->Location = System::Drawing::Point(0, 0);
			this->backgroundPanel->Name = L"backgroundPanel";
			this->backgroundPanel->Size = System::Drawing::Size(607, 372);
			this->backgroundPanel->TabIndex = 0;
			// 
			// groubBox
			// 
			this->groubBox->Controls->Add(this->lab_message);
			this->groubBox->Controls->Add(this->btn_NO);
			this->groubBox->Controls->Add(this->btn_OK);
			this->groubBox->Enabled = false;
			this->groubBox->Location = System::Drawing::Point(65, 48);
			this->groubBox->Name = L"groubBox";
			this->groubBox->Size = System::Drawing::Size(488, 280);
			this->groubBox->TabIndex = 2;
			this->groubBox->TabStop = false;
			this->groubBox->Visible = false;
			this->groubBox->Enter += gcnew System::EventHandler(this, &startingPage::GroupBox1_Enter);
			// 
			// lab_message
			// 
			this->lab_message->AutoSize = true;
			this->lab_message->Location = System::Drawing::Point(69, 99);
			this->lab_message->Name = L"lab_message";
			this->lab_message->Size = System::Drawing::Size(0, 15);
			this->lab_message->TabIndex = 2;
			this->lab_message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_NO
			// 
			this->btn_NO->Location = System::Drawing::Point(310, 218);
			this->btn_NO->Name = L"btn_NO";
			this->btn_NO->Size = System::Drawing::Size(75, 23);
			this->btn_NO->TabIndex = 1;
			this->btn_NO->Text = L"NO";
			this->btn_NO->UseVisualStyleBackColor = true;
			this->btn_NO->Click += gcnew System::EventHandler(this, &startingPage::disableGroupBox);
			// 
			// btn_OK
			// 
			this->btn_OK->Location = System::Drawing::Point(108, 218);
			this->btn_OK->Name = L"btn_OK";
			this->btn_OK->Size = System::Drawing::Size(75, 23);
			this->btn_OK->TabIndex = 0;
			this->btn_OK->Text = L"OK";
			this->btn_OK->UseVisualStyleBackColor = true;
			this->btn_OK->Click += gcnew System::EventHandler(this, &startingPage::initGame);
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(451, 173);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(75, 23);
			this->startButton->TabIndex = 1;
			this->startButton->Text = L"START";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &startingPage::gamestart);
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(120, 174);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(303, 25);
			this->nameTextBox->TabIndex = 0;
			// 
			// startingPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(607, 372);
			this->Controls->Add(this->backgroundPanel);
			this->Name = L"startingPage";
			this->Text = L"startingPage";
			this->backgroundPanel->ResumeLayout(false);
			this->backgroundPanel->PerformLayout();
			this->groubBox->ResumeLayout(false);
			this->groubBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	//player이름 설정 & 알림창 띄우기
	private: System::Void gamestart(System::Object^ sender, System::EventArgs^ e) {

		std::string name = system_to_string(nameTextBox->Text);
		lab_message ->Text = ("캐릭터 이름은 " + string_to_system(name) + "입니다");
		controller->getPlayer()->setName(name);
		groubBox->Enabled = true;
		groubBox->Show();
	}

	private: System::Void GroupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}

	//OK누르면 게임 시작 & 새 화면 띄우기
	private: System::Void initGame(System::Object^ sender, System::EventArgs^ e) {
		this->isCharacterSet = true;
		this->Close();
	}



		 //string to System::string
		 private: std::string system_to_string(System::String^ sys_str)
		 {
			 return  msclr::interop::marshal_as<std::string>(sys_str);
		 }

		//System::string to std::string^
		private: System::String^ string_to_system(std::string str)
		{
			return  msclr::interop::marshal_as<String^>(str);
		}

private: System::Void disableGroupBox(System::Object^ sender, System::EventArgs^ e) {
	//NO버튼 누르면 알림창 지우기
	this->isCharacterSet = false;
	groubBox->Enabled = false;
	groubBox->Visible = false;
	nameTextBox->ResetText();
	lab_message->ResetText();
}
};


}
