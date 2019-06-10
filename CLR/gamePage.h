#pragma once
#include "Controller.h"
#include <list>
#include <array>
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
	/// gamePage에 대한 요약입니다.
	//	matrix[x,y] : map tile
	//	MAX_X, MAX,Y : map의 tile 배열 수 
	//	TILE_SIZE: 그림상 나타낼 한 타일의 사이즈(px)
	//	setMatrixImgs(x,y):타일 하나하나의 이미지 설정. background는 풀/땅, img는 오브젝트.
	//	void setMatrix(): 전체 맵 그리기
	//	imageList_MO: 맵 오브젝트 이미지 저장하는 리스트
	//	imageList_Player: 플레이어 이미지 저장하는 리스트
	/// </summary>
	public ref class gamePage : public System::Windows::Forms::Form
	{
	public:

		Controller* controller = Controller::getInstance();
		Player* player = controller->getPlayer();
		System::ComponentModel::ComponentResourceManager^ rs;


		const int MAX_X = controller->map->MAX_X;
		const int MAX_Y = controller->map->MAX_Y;
		int TILE_SIZE;
		ImageList^ imgList_ground;
		ImageList^ imgList_MO;
		//ImageList^ imgList_player;

		int before_x, before_y;
		//List<Bitmap> imgList_player;
		const int DRY = 0, WET = 1, GRASS = 2;	//imagelist_ground에 쓰기 쉬우라고 이름 정해준것
		
		int moveState = 1;
		Timer animTimer;	//걷는 애니메이션을 위한 타이머
	private: System::ComponentModel::BackgroundWorker^ bgWorker_animate;
	public:

	public:

	public:
		cli::array<PictureBox^, 2> ^ matrix = gcnew cli::array<PictureBox^, 2>(MAX_X, MAX_Y);
		
		gamePage(void)
		{
			InitializeComponent();
			TILE_SIZE = pnl_background->Width / MAX_X;
			setImgList_MO();
			setImgList_ground();
			//setImgList_player();
			
			setMatrix();
			this->picBox_player->Location = System::Drawing::Point(player->getX()*TILE_SIZE, player->gety() * TILE_SIZE - picBox_player->Height + TILE_SIZE);

			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~gamePage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ picBox_player;

	private: System::Windows::Forms::Panel^ pnl_background;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(gamePage::typeid));
			this->pnl_background = (gcnew System::Windows::Forms::Panel());
			this->picBox_player = (gcnew System::Windows::Forms::PictureBox());
			this->bgWorker_animate = (gcnew System::ComponentModel::BackgroundWorker());
			this->pnl_background->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox_player))->BeginInit();
			this->rs = resources;
			this->SuspendLayout();
			// 
			// pnl_background
			// 
			this->pnl_background->Controls->Add(this->picBox_player);
			this->pnl_background->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnl_background->Location = System::Drawing::Point(0, 0);
			this->pnl_background->Name = L"pnl_background";
			this->pnl_background->Size = System::Drawing::Size(1262, 753);
			this->pnl_background->TabIndex = 0;
			this->pnl_background->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &gamePage::Pnl_background_Paint);
			// 
			// picBox_player
			// 
			this->picBox_player->BackColor = System::Drawing::Color::Transparent;
			this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox_player.Image")));
			this->picBox_player->Location = System::Drawing::Point(653, 219);
			this->picBox_player->Name = L"picBox_player";
			this->picBox_player->Size = System::Drawing::Size(33, 63);
			this->picBox_player->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBox_player->TabIndex = 1;
			this->picBox_player->TabStop = false;
			// 
			// bgWorker_animate
			// 
			this->bgWorker_animate->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &gamePage::bgWorker_animate_DoWork);
			this->bgWorker_animate->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &gamePage::BgWorker_animate_ProgressChanged);
			this->bgWorker_animate->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &gamePage::BgWorker_animate_RunWorkerCompleted);
			// 
			// gamePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 753);
			this->Controls->Add(this->pnl_background);
			this->Name = L"gamePage";
			this->Text = L"gamePage";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &gamePage::movePlayer);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &gamePage::KeyDDown);
			this->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &gamePage::do_nothing);
			this->pnl_background->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox_player))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void PictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	//전체 맵 화면에 그리기
	private: void setMatrix()
	{
		for (int i = 0; i < MAX_X; i++)
		{
			for (int j = 0; j < MAX_Y; j++)
			{
				matrix[i, j] = gcnew System::Windows::Forms::PictureBox();
				setMatrixImgs(i, j);
				this->matrix[i,j]->Location = System::Drawing::Point(i*TILE_SIZE, j*TILE_SIZE);
				this->matrix[i,j]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->matrix[i,j]->Size = System::Drawing::Size(TILE_SIZE, TILE_SIZE);

				//this->matrix[i,j]->TabIndex = 0;
				//this->matrix[i,j]->TabStop = false;

				this->pnl_background->Controls->Add(this->matrix[i,j]);
				this->matrix[i, j]->Show();
			}
		}

	}

	//타일 하나하나의 이미지 설정. background는 풀/땅, img는 오브젝트.
	private: void setMatrixImgs(int x, int y)
	{
		//background 땅/풀 설정
		int state = (!controller->map->gettile(x, y)->getCanSeed()) ? GRASS: 
			controller->map->gettile(x,y)->getIsWet()? WET:DRY;
		this->matrix[x, y]->BackgroundImage = imgList_ground->Images[state];

		//map object 설정
		MapObject* objPtr = controller->map->gettile(x, y)->getObject();
		if (objPtr == nullptr || objPtr->getObjectType() == NULL) return;
		matrix[x, y]->Image = imgList_MO->Images[objPtr->getObjectType()];
	}


	private: System::Void Pnl_background_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
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


	 void setImgList_MO()
	{
		 imgList_MO = gcnew ImageList();
		 imgList_MO->ColorDepth = ColorDepth::Depth32Bit;

		 //imgList_MO->ImageSize::StretchImage;

		 imgList_MO->Images->Add(Image::FromFile("./images/tree.png"));
		 imgList_MO->Images->Add(Image::FromFile("./images/stone.png"));

		 //TODO:임시로 추가해놓음. 씨앗&npc로 바꿀 것
		 imgList_MO->Images->Add(Image::FromFile("./images/seed.png"));
		 imgList_MO->Images->Add(Image::FromFile("./images/stone.png"));
	}

	 void setImgList_ground()
	 {
		 imgList_ground = gcnew ImageList();
		 imgList_ground->ColorDepth = ColorDepth::Depth32Bit;

		 imgList_ground->Images->Add(Image::FromFile("./images/dryDirt.png"));
		 imgList_ground->Images->Add(Image::FromFile("./images/wetDirt.png"));
		 imgList_ground->Images->Add(Image::FromFile("./images/grass.png"));
	 }
/*
	 void setImgList_player()
	 {
		 imgList_player = gcnew ImageList();
		 imgList_player->ColorDepth = ColorDepth::Depth32Bit;


		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_down1.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_down2.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_down3.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_down4.png"));

		 imgList[4]-[7] : up
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_up1.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_up2.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_up3.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_up4.png"));

		 imgList[8]-[11] : right
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_right1.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_right2.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_right3.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_right4.png"));

		 imgList[12]-[15] : left
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_left1.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_left2.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_left3.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_left4.png"));
	 }*/


	
private: System::Void movePlayer(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	bgWorker_animate->WorkerReportsProgress = true;

	if(!bgWorker_animate->IsBusy) bgWorker_animate->RunWorkerAsync(e->KeyValue);

}
	
private: System::Void do_nothing(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e) {
	//this->picBox_player->Visible = false;
}


private: System::Void bgWorker_animate_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {

	before_x = player->getX();
	before_y = player->gety();

	player->move((int)(e->Argument));
	
	while (moveState++ < 5)
	{
		Sleep(100);
		this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject(getStateStr()+moveState)));
		bgWorker_animate->ReportProgress(moveState);
	}
	moveState = 1;
}
private: System::Void BgWorker_animate_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
	
	int _x = before_x * TILE_SIZE +  (player->getX() - before_x) * e->ProgressPercentage * TILE_SIZE / 4;
	int _y = before_y * TILE_SIZE - picBox_player->Height + TILE_SIZE + (player->gety() - before_y) * e->ProgressPercentage * TILE_SIZE / 4;
	this->picBox_player->Location = System::Drawing::Point(_x, _y);
}
private: System::Void BgWorker_animate_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
	this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject(getStateStr() + moveState)));
	int _x = player->getX() * TILE_SIZE;
	int _y = player->gety() * TILE_SIZE - picBox_player->Height + TILE_SIZE;
	this->picBox_player->Location = System::Drawing::Point(_x, _y);


}

	//스페이스바 누를 시, 씨 뿌리기, 물뿌리기, 오브젝트 없애기를 조사후 진행
private: System::Void KeyDDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	Player* p = controller->getPlayer();

	int k = (int)(e->KeyCode);
	int s = p->getStatue();
	int x = p->getX();
	int y = p->gety();

	if (s == 0) {
		x = x - 1;
	}
	else if (s == 1) {
		x = x + 1;
	}
	else if (s == 2) {
		y = y + 1;
	}
	else if (s == 3) {
		y = y - 1;
	}


	if (k == 32) {
		player->interact();
		setMatrixImgs(player->getTarget()->getx(), player->getTarget()->gety());

		/*if (true == controller->map->gettile(x, y)->getCanSeed()) {
			controller->map->gettile(x, y)->setObject(new Harvest);
			matrix[x, y]->Image = imgList_MO->Images[harvest];
			controller->map->gettile(x, y)->setCanSeed(false);
			controller->map->gettile(x, y)->setIsWet(false);

		}
		else if (false == controller->map->gettile(x, y)->getIsWet()) {
			int state = (controller->map->gettile(x, y)->getIsWet()) ? WET : GRASS;
			this->matrix[x, y]->BackgroundImage = imgList_ground->Images[state];
			controller->map->gettile(x, y)->setIsWet(true);
		}*/

		 if (nullptr != controller->map->gettile(x, y)->getObject()) {
			MapObject* objPtr = controller->map->gettile(x, y)->getObject();
			int h = objPtr->getHealth();
			h = h - 10;
			objPtr->setHealth(h);

			if (h <= 60) {
				this->matrix[x, y]->Image = nullptr;
				controller->map->gettile(x, y)->setCanMove(true);
			}
		}
	}


	

}
		 System::String^ getStateStr()
		 {
			 std::string str[4] = { "left","right", "down", "up" };
			 return string_to_system(str[player->getStatue()]);
		 }

};




}