/**
 * @file Machine2Factory.cpp
 * @author Lance Y.
 */

#include "pch.h"
#include "Machine2Factory.h"
#include "Machine.h"
#include "Shape.h"
#include "Motor.h"
#include "Pulley.h"
#include "SnowBlowerBody.h"

/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";

/**
 * Constructor
 * @param resourcesDir Path to the resources directory
 */
Machine2Factory::Machine2Factory(std::wstring resourcesDir) :
    mResourcesDir(resourcesDir)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
}


/**
 * Factory method to create machine #2
 * @return
 */
std::shared_ptr<Machine> Machine2Factory::Create()
{
// The machine itself
    auto machine = std::make_shared<Machine>(2);

//    const int BackgroundWidth = 500;
//    const int BackgroundHeight = 350;

    const int BaseWidth = 325;  // Width of the base
    const int BaseHeight = 40;  // Height of the base

    const int MotorX = -10; // Motor X location
    const int MotorY = -78;	// Motor Y location

    const int Post1X = 80;	// Second post X location
    const int Post2X = -70;	// Post X location

    /*
    const int CatWidth = 130;
    const int CatHeight = 110;
    const int CatOffset = 60;
    */

    const int SnowBlowerWidth = 120;
    const int SnowBlowerHeight = 174;
    const int SnowBlowerCenterOffset = 60;

    int Post1Height = 120;
    int Post2Height = 200;

    //
    // The base
    //
    auto base = std::make_shared<Shape>();

    base->Rectangle(int(-BaseWidth/2), 0, BaseWidth, BaseHeight);
    base->SetImage(mImagesDir + L"/base.png");
    machine->AddComponent(base);

    //
    // The motor
    //
    auto motor =  std::make_shared<Motor>(mImagesDir);
    motor->CenteredSquare(80);
    motor->SetImage(mImagesDir + L"/motor3.png");
    motor->SetPosition(MotorX, MotorY);
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);


    //
    // The snow blower
    //
    auto blower =  std::make_shared<SnowBlowerBody>(mImagesDir);
    blower->Rectangle(-SnowBlowerWidth / 2, SnowBlowerCenterOffset, SnowBlowerWidth, SnowBlowerHeight);
    blower->SetImage(mImagesDir + L"/blowerR.png");
    blower->SetPosition(Post1X, -150);
    blower->SetRotation(0.15);
    blower->SetIncrementSnow();
    blower->SetOscillate();
    blower->SetYellowSnow();
    machine->AddComponent(blower);

    /*
    //
    // The cat blower
    //
    auto cat =  std::make_shared<SnowBlowerBody>(mImagesDir);
    cat->Rectangle(-CatWidth+80, CatOffset-50, CatWidth, CatHeight);
    cat->SetImage(mImagesDir + L"/cat2.png");
    cat->SetPosition(Post1X, -150);
    cat->SetRotation(0.15);
    machine->AddComponent(cat);
    */

    //
    // Post to hold the first pulley
    // Must be added before the motor pulley so it draws behind the belt
    //
    auto post1 = CreatePost(Post1X, -40, 20, Post1Height, wxColor(10, 10, 10));
    machine->AddComponent(post1);

    //
    // Post to hold the second pully
    //
    auto post2 = CreatePost(Post2X, -40, 20, Post2Height, wxColor(10, 10, 10));
    machine->AddComponent(post2);

    //
    // The pulley driven by the motor
    // Radius=15pixels
    //
    auto pulley1 = std::make_shared<Pulley>(15);
    pulley1->SetImage(mImagesDir + L"/pulley2.png");
    pulley1->SetPosition(MotorX, -38 - motor->GetSize() / 2);
    pulley1->SetPhase(0.1);	// Rotate it a little bit
    pulley1->SetFlappyBelts();
    machine->AddComponent(pulley1);


    // This is how I make a connection from a source to a sink.
    // This is the case where they are driven at the same speed.
    motor->GetSource()->AddSink(pulley1->GetSink());


    //
    // The pulley on the snow cat. Driven by the motor pulley.
    // Radius=40pixels
    //
    auto pulley2 = std::make_shared<Pulley>(40);
    pulley2->SetImage(mImagesDir + L"/pulley.png");
    pulley2->SetPosition(Post1X, post1->GetY() - Post1Height + 10);
    pulley2->SetPhase(0.1);	// Rotate it a little bit
    pulley2->SetFlappyBelts();
    machine->AddComponent(pulley2);

    pulley2->GetSource()->AddSink(blower->GetSink());


    // This is how I make a connection from a pully
    // to another pully using a belt.
    pulley1->Drive(pulley2);


    //
    // Pulley directly driven by that pulley
    // Radius=15px
    //
    auto pulley3 = std::make_shared<Pulley>(15);
    pulley3->SetImage(mImagesDir + L"/pulley2.png");
    pulley3->SetPosition(Post1X, post1->GetY() - Post1Height + 10);
    pulley3->SetFlappyBelts();
    machine->AddComponent(pulley3);

    pulley2->GetSource()->AddSink(pulley3->GetSink());

    //
    // Pully on the second post
    //
    auto pulley4 = std::make_shared<Pulley>(40);
    pulley4->SetImage(mImagesDir + L"/pulley.png");
    pulley4->SetPosition(Post2X, post2->GetY() - Post2Height + 10);
    pulley4->SetPhase(0.1);	// Rotate it a little bit
    pulley4->SetFlappyBelts();
    machine->AddComponent(pulley4);

    pulley3->Drive(pulley4);

    //
    // The flag
    //
    auto flag = std::make_shared<Shape>();
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetImage(mImagesDir + L"/flag.png");
    flag->SetPosition(Post2X, post2->GetY() - Post2Height + 10);
    machine->AddComponent(flag);

    pulley4->GetSource()->AddSink(flag->GetSink());


    return machine;
}

/**
 * Create a shape to use as a post to hold pulleys.
 *
 * I create several posts. This function just makes it easier to do.
 *
 * \param x X position of bottom center of post in pixels
 * \param y Y position of bottom of post in pixels
 * \param wid Post width in pixels
 * \param hit Post height in pixels
 * \param color Color to apply to the post
 * \return Shape object
 */
std::shared_ptr<Shape> Machine2Factory::CreatePost(int x, int y, int wid, int hit, wxColor color)
{
    auto post = std::make_shared<Shape>();
    post->Rectangle(-wid/2, 0, wid, hit);
    post->SetColor(color);
    post->SetPosition(x, y);

    return post;
}
