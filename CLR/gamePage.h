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
		ImageList^ imgList_player;

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
			//rs = (gcnew System::ComponentModel::ComponentResourceManager(gamePage::typeid));
			TILE_SIZE = pnl_background->Width / MAX_X;
			setImgList_MO();
			setImgList_ground();
			setImgList_player();
			
			setMatrix();
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ pnl_background;
	private: System::Windows::Forms::PictureBox^ picBox_dirt;
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
			//
			//내가 임의로 추가
			rs = resources;
			//
			//
			this->pnl_background = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picBox_player = (gcnew System::Windows::Forms::PictureBox());
			this->picBox_dirt = (gcnew System::Windows::Forms::PictureBox());
			this->bgWorker_animate = (gcnew System::ComponentModel::BackgroundWorker());
			this->pnl_background->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox_player))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox_dirt))->BeginInit();
			this->SuspendLayout();
			// 
			// pnl_background
			// 
			this->pnl_background->Controls->Add(this->label1);
			this->pnl_background->Controls->Add(this->picBox_player);
			this->pnl_background->Controls->Add(this->picBox_dirt);
			this->pnl_background->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnl_background->Location = System::Drawing::Point(0, 0);
			this->pnl_background->Name = L"pnl_background";
			this->pnl_background->Size = System::Drawing::Size(1262, 753);
			this->pnl_background->TabIndex = 0;
			this->pnl_background->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &gamePage::Pnl_background_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(395, 116);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// picBox_player
			// 
			this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox_player.Image")));
			this->picBox_player->Location = System::Drawing::Point(653, 219);
			this->picBox_player->Name = L"picBox_player";
			this->picBox_player->Size = System::Drawing::Size(33, 63);
			this->picBox_player->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBox_player->TabIndex = 1;
			this->picBox_player->TabStop = false;
			// 
			// picBox_dirt
			// 
			this->picBox_dirt->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox_dirt.BackgroundImage")));
			this->picBox_dirt->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picBox_dirt->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox_dirt.Image")));
			this->picBox_dirt->Location = System::Drawing::Point(185, 113);
			this->picBox_dirt->Name = L"picBox_dirt";
			this->picBox_dirt->Size = System::Drawing::Size(31, 34);
			this->picBox_dirt->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBox_dirt->TabIndex = 0;
			this->picBox_dirt->TabStop = false;
			this->picBox_dirt->Click += gcnew System::EventHandler(this, &gamePage::PictureBox1_Click);
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
			this->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &gamePage::do_nothing);
			this->pnl_background->ResumeLayout(false);
			this->pnl_background->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox_player))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox_dirt))->EndInit();
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
		int state = (controller->map->gettile(x, y)->getCanSeed()) ? DRY : GRASS;
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
		 imgList_MO->Images->Add(Image::FromFile("./images/stone.png"));
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

	 void setImgList_player()
	 {
		 imgList_player = gcnew ImageList();
		 imgList_player->ColorDepth = ColorDepth::Depth32Bit;

		 //imgList[0]-[3] : down
		 //System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(gamePage::typeid));

		//this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox_player.Image")));
		/* this->imgList_player->Images->Add(cli::safe_cast<System::Drawing::Image^>(rs->GetObject(L"Leah_down1")));
		 this->imgList_player->Images->Add(cli::safe_cast<System::Drawing::Image^>(rs->GetObject(L"Leah_down2")));
		 this->imgList_player->Images->Add(cli::safe_cast<System::Drawing::Image^>(rs->GetObject(L"Leah_down3")));
		 this->imgList_player->Images->Add(cli::safe_cast<System::Drawing::Image^>(rs->GetObject(L"Leah_down4")));*/

		 //this->picBox_dirt->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox_dirt.Image")));

		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_down1.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_down2.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_down3.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_down4.png"));

		 //imgList[4]-[7] : up
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_up1.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_up2.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_up3.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_up4.png"));

		 //imgList[8]-[11] : right
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_right1.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_right2.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_right3.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_right4.png"));

		 //imgList[12]-[15] : left
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_left1.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_left2.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_left3.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_left4.png"));
	 }


	
private: System::Void movePlayer(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	this->label1->Text = (e->KeyValue).ToString();

	//movingAnimation(sender, e);
	//movingAnimation();
	bgWorker_animate->WorkerReportsProgress = true;

	if(!bgWorker_animate->IsBusy) bgWorker_animate->RunWorkerAsync(e->KeyValue);


	//player의 좌표 변경
	/*this->player->move(e->KeyValue);
	int _x = player->getX() * TILE_SIZE;
	int _y = player->gety() * TILE_SIZE - picBox_player->Height + TILE_SIZE;
	this->picBox_player->Location = System::Drawing::Point(_x, _y);
	this->picBox_player->Show();*/
	
/*
	int k = (int)(e->KeyCode);
	p->move((int)(e->KeyCode));
	panel7->Location = System::Drawing::Point(p->getX(), p->gety());
	int x = p->getX();
	int y = p->gety();

	if (k == 32) {
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
*/


}
	
//캐릭터가 움직이는 애니메이션 설정
		 //void movingAnimation(Object^ sender, EventArgs^ e)
		 void movingAnimation()
		 {
			 //picBox_player->Image = imgList_player->Images[1];

			 //TODO: 이미지 변화
			 while (++moveState < 4)
			 {
				this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject(L"Leah_down"+moveState)));
				//Sleep(100);
			 }

			 this->moveState = 0;
			 //picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Leah_down2")));
			 //picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Leah_down2")));

			 //this->picBox_player->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;

			 //this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Leah_down2.Image")));

			 //picBox_player->
				//picBox_player->ColorDepth = ColorDepth::Depth32Bit;
			 //this->picBox_player->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			 /*
			 while (moveState < 4)
			 {
				picBox_player->Image = imgList_player->Images[moveState++];
				Sleep(10);
			 }
			 moveState = 0;*/
		 }

private: System::Void do_nothing(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e) {
	//this->picBox_player->Visible = false;
}


private: System::Void bgWorker_animate_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	//list<Object>^ arguments;
	//= new list<Object>();
	//arguments.push_back(player->getX());
	//arguments.push_back(player->gety());

	before_x = player->getX();
	before_y = player->gety();

	//int	_x = player->getX() * TILE_SIZE;
	//int _y = player->gety() * TILE_SIZE - picBox_player->Height + TILE_SIZE;

	player->move((int)(e->Argument));
	//arguments.push_back(player->getX());
	//arguments.push_back(player->gety());
	//Tile* before = player->getNowTile();
	//Tile* after = player->getNowTile();


	while (moveState++ < 5)
	{
		//Thread.Sleep(500);
		Sleep(300);
		//this->label1->Text = ("Leah_down" + moveState);
		//string s1 = system_to_string("Leah_down") + system_to_string(moveState.ToString());
		//System::String^ src = string_to_system(s1);
		//this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject(L"Leah_down" + moveState.ToString())));
		//this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject(src)));


		this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject("Leah_down"+moveState)));
		/*_x += TILE_SIZE / 4;
		_y += TILE_SIZE / 4;
		this->picBox_player->Location = System::Drawing::Point(_x, _y);*/
		
		
		//this->picBox_player->Show();
		//this->picBox_player->Location
		//var image = LoadAnImage(myState);
		bgWorker_animate->ReportProgress(moveState);
	}
	moveState = 1;
	//int toMove = (int)e->Argument;
	//player->move(toMove);
	//e->Result = e->Argument;

	//this->bgWorker_animate->CancelAsync();

}
private: System::Void BgWorker_animate_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
	//pictureBox1.Image = (Image)e.UserState;
	//picBox_player->Image = imgList_player->Images[moveState++];
	//if (moveState >= 4) moveState = 0;

	//e->ProgressPercentage

	//this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject("Leah_down" + moveState)));
	//_x += TILE_SIZE / 4;
	//_y += TILE_SIZE / 4;
	//this->picBox_player->Location = System::Drawing::Point(_x, _y);
	int _x = before_x * TILE_SIZE +  (player->getX() - before_x) * e->ProgressPercentage * TILE_SIZE / 4;
	int _y = before_y * TILE_SIZE - picBox_player->Height + TILE_SIZE + (player->gety() - before_y) * e->ProgressPercentage * TILE_SIZE / 4;
	this->picBox_player->Location = System::Drawing::Point(_x, _y);



}
private: System::Void BgWorker_animate_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
	this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject("Leah_down" + moveState)));
	int _x = player->getX() * TILE_SIZE;
	int _y = player->gety() * TILE_SIZE - picBox_player->Height + TILE_SIZE;
	this->picBox_player->Location = System::Drawing::Point(_x, _y);

	//int toMove = (int)e->Result;
	//this->player->move(toMove);

}
};




}