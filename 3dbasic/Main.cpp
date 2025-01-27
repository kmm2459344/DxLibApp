#include < DxLib.h>

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int model1;
	VECTOR pos = VGet(600.0f, 300.0f, -400.0f);
	int key;

	ChangeWindowMode(TRUE);
	SetGraphMode(1200, 800, 32);
	if (DxLib_Init() == -1) {
		return -1;
	}
	//���f���ǂݍ���                         // �����ȉ��S�s�ǉ�
	model1 = MV1LoadModel("Player/PC.mv1");
	if (model1 == -1) {
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (key & PAD_INPUT_DOWN) pos.z -= 4.0f;
		if (key & PAD_INPUT_UP) pos.z += 4.0f;
		if (key & PAD_INPUT_LEFT) pos.x -= 4.0f;
		if (key & PAD_INPUT_RIGHT) pos.x += 4.0f;


		ClearDrawScreen();
		DrawBox(0, 0, 600, 400, GetColor(255, 255, 0), TRUE);

		MV1SetPosition(model1, pos);
		MV1DrawModel(model1);  // �����ǉ�

		ScreenFlip();

	}
	DxLib_End();

	return 0;
}