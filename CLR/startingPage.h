#pragma once
#include "Controller.h"
namespace CLRFInal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// startingPage�� ���� ����Դϴ�.
	/// </summary>
	public ref class startingPage : public System::Windows::Forms::Form
	{
	public:
		static Controller* controller = Controller::getInstance();
		startingPage(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
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
	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(startingPage::typeid));
			this->backgroundPanel = (gcnew System::Windows::Forms::Panel());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->backgroundPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// backgroundPanel
			// 
			this->backgroundPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backgroundPanel.BackgroundImage")));
			this->backgroundPanel->Controls->Add(this->startButton);
			this->backgroundPanel->Controls->Add(this->nameTextBox);
			this->backgroundPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->backgroundPanel->Location = System::Drawing::Point(0, 0);
			this->backgroundPanel->Name = L"backgroundPanel";
			this->backgroundPanel->Size = System::Drawing::Size(869, 380);
			this->backgroundPanel->TabIndex = 0;
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(593, 173);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(75, 23);
			this->startButton->TabIndex = 1;
			this->startButton->Text = L"START";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &startingPage::gamestart);
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(178, 171);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(396, 25);
			this->nameTextBox->TabIndex = 0;
			// 
			// startingPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(869, 380);
			this->Controls->Add(this->backgroundPanel);
			this->Name = L"startingPage";
			this->Text = L"startingPage";
			this->backgroundPanel->ResumeLayout(false);
			this->backgroundPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		//TODO: gamestart ��ư �̺�Ʈ
	private: System::Void gamestart(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}
