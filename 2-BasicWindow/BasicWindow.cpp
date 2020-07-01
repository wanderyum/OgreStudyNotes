#include <Ogre.h>
#include <Bites/OgreApplicationContext.h>

class BasicWindow : public OgreBites::ApplicationContext, public OgreBites::InputListener
{
public:
    BasicWindow();
    void setup();
    bool keyPressed(const OgreBites::KeyboardEvent& evt);
};

/* 构造器，实际上调用的是ApplicationContextBase的构造器，作用仅是初始化了几个变量。具体参见：
 * ogre-1.12.6/Components/Bites/src/OgreApplicationContextBase.cpp
 */
BasicWindow::BasicWindow() : OgreBites::ApplicationContext("OgreTutorialApp"){
}

/* setup方法，重写了ApplicationContextBase的setup方法 */
void BasicWindow::setup(void)
{
    /** 首先调用父类setup方法 */
    OgreBites::ApplicationContextBase::setup();
    
    // register for input events
    addInputListener(this);

    /** setup方法被initapp方法调用，在调用前已经创建好了Root */
    Ogre::Root* root = getRoot();
    Ogre::SceneManager* scnMgr = root->createSceneManager();

    // register our scene with the RTSS
    Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);

    /** 设置环境光线，否则只能看到黑屏 */
    scnMgr->setAmbientLight(Ogre::ColourValue(0.8, 0.8, 0.8));

    /** 设置camera：
     *  1. 建立一个场景节点(SceneNode)，设置好位置方向
     *  2. 建立一个camera对象，和前面的场景节点绑定
     */
    Ogre::SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    camNode->setPosition(0, 0, 15);
    camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

    Ogre::Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5);    /* 距离为5以内的对象不被显示 */
    cam->setAutoAspectRatio(true);  /* 自动设置屏幕宽高比 */
    camNode->attachObject(cam);

    /** 指定cam的成像结果为最终显示结果 */
    Ogre::Viewport* vp = getRenderWindow()->addViewport(cam);

    /** 添加要显示的人物 */
    Ogre::Entity* ent = scnMgr->createEntity("Sinbad.mesh");
    Ogre::SceneNode* node = scnMgr->getRootSceneNode()->createChildSceneNode();
    node->attachObject(ent);
}

/** 处理按键响应事件 */
bool BasicWindow::keyPressed(const OgreBites::KeyboardEvent& evt)
{
    if (evt.keysym.sym == OgreBites::SDLK_ESCAPE)
    {
        getRoot()->queueEndRendering();
    }
    return true;
}

int main(int argc, char *argv[])
{
    BasicWindow bWindow;

    /** 这里的initApp方法用的是ApplicationContextBase的initApp方法，做了这么几件事：
     *  1. 创建Root和OverlaySystem (调用createRoot方法)
     *  2. 调用setup方法
     */
    bWindow.initApp();

    /** 开始渲染
     *  每渲染一帧检查一遍mQueuedEnd的值，如果为true则停止渲染
     *  渲染过程中扫描并处理事件(按键事件、鼠标事件等)
     */
    bWindow.getRoot()->startRendering();
    bWindow.closeApp();
    return 0;
}