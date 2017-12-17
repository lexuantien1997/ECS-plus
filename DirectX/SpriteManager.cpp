#include "SpriteManager.h"
#include "Sprite.h"



void SpriteManager::attachResource(Resource * resource)
{
	resourceInitialize.emplace(resource->getName(), resource);
}


Resource * SpriteManager::find(string name)
{
	map<string, Resource*>::iterator it = resourceInitialize.find(name);
	if (it!=resourceInitialize.end())
	{
		return resourceInitialize[name];
	}
	return NULL;
}

LPD3DXSPRITE SpriteManager::getSpriteHandler()
{
	return spriteHandler;
}

SpriteManager::SpriteManager()
{
	LPDIRECT3DDEVICE9 d3ddv = DeviceManager::getInstance()->getDevice();

	D3DXCreateSprite(d3ddv, &spriteHandler);

	HRESULT res = D3DXCreateSprite(d3ddv, &spriteHandler);

}


SpriteManager::~SpriteManager()
{
}

// full parameters about drawing
void SpriteManager::draw(SpriteComponent* spritecomp, Transform* t, Camera cam)
{
	// set position:
	// vị trí của bức hình từ transform
	D3DXVECTOR4 position = D3DXVECTOR4(t->getPosition().x, t->getPosition().y, 0, 0);

	// set source rect:
	// Trong bức hình chính lấy ra bao nhiêu phần
	Rect r = spritecomp->getRect();

	RECT sourceRect;
	sourceRect.left = r.left_top.x;
	sourceRect.top = r.left_top.y;
	sourceRect.right = sourceRect.left + r.size.x;
	sourceRect.bottom = sourceRect.top + r.size.y;

	// set rotation:
	// Lấy góc xoay của hình từ transform
	float rotation = t->getRotation();

	// set translation: NULL

	// set origin:
	// Lấy tâm xoay từ transform 
	Vector2f ori = t->getOrigin();
	D3DXVECTOR2 rotationCenter = D3DXVECTOR2(ori.x, ori.y);

	// set scale:
	// Lấy độ co dãn của hình, phóng to hay thu nhỏ từ transform
	Vector2f sca = t->getScale();
	D3DXVECTOR2 scaling = D3DXVECTOR2(sca.x, sca.y);

	// scaling center:
	D3DXVECTOR2 scalingScenter = D3DXVECTOR2(t->getPosition().x + ori.x, t->getPosition().y - ori.y);
	
	D3DXMATRIX matrix;

	D3DXMatrixTransformation2D(
		&matrix,
		&scalingScenter,
		0,
		&scaling,
		&rotationCenter,
		D3DXToRadian(rotation),
		0
	);

	D3DXMATRIX oldMatrix;
	spriteHandler->GetTransform(&oldMatrix);
	spriteHandler->SetTransform(&matrix);

	//Camera
	D3DXMATRIX transformMatrix;
	D3DXMatrixIdentity(&transformMatrix);

	transformMatrix._22 = -1.0f;
	transformMatrix._41 = -cam.getCamPosition().x;
	transformMatrix._42 = cam.getCamPosition().y;



	D3DXVECTOR4 result;
	D3DXVec4Transform(&result, &position, &transformMatrix);

	D3DXVECTOR3 realPositionInCamera(result.x, result.y, 0);

	// vị trí vẽ sẽ là giữa bức hình hay không
	//D3DXVECTOR3* isCenter  = new D3DXVECTOR3(r.size.x / 2, r.size.y / 2, 0);
	D3DXVECTOR3* isCenter = new D3DXVECTOR3(0, r.size.y, 0);
	
	begin(); // start drawing

	spriteHandler->Draw(
		spritecomp->getSprite()->getTexture(), // image
		&sourceRect, // rect
		isCenter,
		&realPositionInCamera, // position
		spritecomp->getSprite()->getColor() // transparent color
	);

	spriteHandler->SetTransform(&oldMatrix);

	end(); // finish
}

void SpriteManager::drawTile(SpriteComponent* spritecomp, Transform* t, Camera cam)
{

	// set source rect:
	// Trong bức hình chính lấy ra bao nhiêu phần
	Rect r = spritecomp->getRect();

	RECT sourceRect;
	sourceRect.left = r.left_top.x;
	sourceRect.top = r.left_top.y;
	sourceRect.right = sourceRect.left + r.size.x;
	sourceRect.bottom = sourceRect.top + r.size.y;


	//Camera
	D3DXMATRIX transformMatrix;
	D3DXMatrixIdentity(&transformMatrix);

	transformMatrix._22 = -1.0f;
	transformMatrix._41 = -cam.getCamPosition().x;
	transformMatrix._42 = cam.getCamPosition().y;

	// set position:
	// vị trí của bức hình từ transform
	D3DXVECTOR4 position = D3DXVECTOR4(t->getPosition().x, t->getPosition().y, 0, 0);
	D3DXVECTOR4 result;
	D3DXVec4Transform(&result, &position, &transformMatrix);

	D3DXVECTOR3 realPositionInCamera(result.x, result.y, 0);

	// vị trí vẽ sẽ là giữa bức hình hay không
	//D3DXVECTOR3* isCenter  = new D3DXVECTOR3(r.size.x / 2, r.size.y / 2, 0);
	D3DXVECTOR3* isCenter = new D3DXVECTOR3(0, r.size.y, 0);

	begin(); // start drawing

	spriteHandler->Draw(
		spritecomp->getSprite()->getTexture(), // image
		&sourceRect, // rect
		isCenter,
		&realPositionInCamera, // position
		spritecomp->getSprite()->getColor() // transparent color
	);
	end(); // finish
}

void SpriteManager::drawLeftTopTransform(SpriteComponent* spritecomp, Transform* t, Camera cam)
{
	// set position:
	// vị trí của bức hình từ transform
	D3DXVECTOR4 position = D3DXVECTOR4(t->getPosition().x, t->getPosition().y, 0, 0);

	// set source rect:
	// Trong bức hình chính lấy ra bao nhiêu phần
	Rect r = spritecomp->getRect();

	RECT sourceRect;
	sourceRect.left = r.left_top.x;
	sourceRect.top = r.left_top.y;
	sourceRect.right = sourceRect.left + r.size.x;
	sourceRect.bottom = sourceRect.top + r.size.y;

	// set rotation:
	// Lấy góc xoay của hình từ transform
	float rotation = t->getRotation();

	// set translation: NULL

	// set origin:
	// Lấy tâm xoay từ transform 
	Vector2f ori = t->getOrigin();
	D3DXVECTOR2 rotationCenter = D3DXVECTOR2(ori.x, ori.y);

	// set scale:
	// Lấy độ co dãn của hình, phóng to hay thu nhỏ từ transform
	Vector2f sca = t->getScale();
	D3DXVECTOR2 scaling = D3DXVECTOR2(sca.x, sca.y);

	// scaling center:
	D3DXVECTOR2 scalingScenter = D3DXVECTOR2(t->getPosition().x + ori.x, t->getPosition().y - ori.y);

	D3DXMATRIX matrix;

	D3DXMatrixTransformation2D(
		&matrix,
		&scalingScenter,
		0,
		&scaling,
		&rotationCenter,
		D3DXToRadian(rotation),
		0
	);

	D3DXMATRIX oldMatrix;
	spriteHandler->GetTransform(&oldMatrix);
	spriteHandler->SetTransform(&matrix);

	//Camera
	D3DXMATRIX transformMatrix;
	D3DXMatrixIdentity(&transformMatrix);

	transformMatrix._22 = -1.0f;
	transformMatrix._41 = -cam.getCamPosition().x;
	transformMatrix._42 = cam.getCamPosition().y;



	D3DXVECTOR4 result;
	D3DXVec4Transform(&result, &position, &transformMatrix);

	D3DXVECTOR3 realPositionInCamera(result.x, result.y, 0);

	// vị trí vẽ sẽ là giữa bức hình hay không
	//D3DXVECTOR3* isCenter  = new D3DXVECTOR3(r.size.x / 2, r.size.y / 2, 0);
	D3DXVECTOR3* isCenter = new D3DXVECTOR3(0, r.size.y, 0);

	begin(); // start drawing

	spriteHandler->Draw(
		spritecomp->getSprite()->getTexture(), // image
		&sourceRect, // rect
		NULL,
		&realPositionInCamera, // position
		spritecomp->getSprite()->getColor() // transparent color
	);

	spriteHandler->SetTransform(&oldMatrix);

	end(); // finish
}

void SpriteManager::begin()
{
	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
}

void SpriteManager::end()
{
	spriteHandler->End();
}
