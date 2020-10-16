# Software Requirements Specifications for Send Me Home (A Platformer Game) 

## Table of contents
[Sections 1-2](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#sections-1-2)

[1. Introduction](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#1-introduction)

[1.1. Purpose](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#11-purpose)

[1.2. Conventions](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#12-conventions)

[1.3. Intended audience](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#13-intended-audience)

[2. Overall Description](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#2-overall-description)

[2.1. Product description](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#21-product-description)

[2.2. Product features](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#22-product-features)

[2.3. Operating environment](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#23-operating-environment)

[2.4. Constraints](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#24-constraints)

[2.5. User documentation](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#25-user-documentation)

[2.6. Assumptions and dependencies](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#26-assumptions-and-dependencies)

[Section 3](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#section-3)

[3. System Features](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#3-system-features)

[3.1. Functional requirement 1](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#31-functional-requirement-1)

[3.1.1. Description and priority](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#311-description-and-priority)

[3.1.2. Stimulus and response](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#312-stimulus-and-response)

[3.1.3. Functional requirements](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#313-functional-requirements)

[3.2. Functional requirement 2](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#32-functional-requirement-2)

[3.2.1. Description and priority](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#321-description-and-priority)

[3.2.2. Stimulus and response](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#322-stimulus-and-response)

[3.2.3. Functional requirements](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#323-functional-requirements)

[Section 4](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#section-4)

[4. Nonfunctional Requirements](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#4-nonfunctional-requirements)

[4.1 Nonfunctional Requirement 1](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#41-nonfunctional-requirement-1)

[4.1.1 Description](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#411-description)

[4.2 Nonfunctional Requirement 2](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#42-nonfunctional-requirement-2)

[4.2.1 Description](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#421-description)

[Appendix A](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#appendix-a-class-diagram)

[Appendix B](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Requirements%20Documentation.md#appendix-b-one-other-diagram)

## Revision history
Version | Author | Date
--------|--------|-----
Version 1.0 | Bryce Mecham | 10/15/2020

## Sections 1-2:

### 1. Introduction

#### 1.1. Purpose
We are creating a platformer type game for the purposes of entertainment, as a resume builder, and to complete CS 2450. This document will outline the software requirements for our project. 
#### 1.2. Conventions
The platformer will be written in C++ using the engine Coco-2dx. It hopefully will be exported to the Google Play store and/or the Apple Appstore. Our team consists of Adam Maxwell as team leader and code quality manager, Bryce Mecham as developer and code testing manager, and Yucheng Long as developer and documentation manager.
#### 1.3. Intended audience
The intended audience is future employers, our professor, and anyone who likes to play platformer games.
### 2. Overall Description

#### 2.1. Product description
Our goal is to create a platformer game that can be used across platforms. The concept is an alien whose spaceship has broken down, and to fix it he must collect parts by completing levels which could include trying not to fall or land on dangerous terrain and avoid creatures. We will use a game engine (Cocos2d-x) to create the game.
#### 2.2. Product features
- Primary goals
  - Build a platformer game that is cross platform.
  - Levels which the goal is to collect parts to fix the alien's spaceship.
  - Final goal is to collect enough parts to fix the spaceship and get off the planet.
  - Make menus for the settings, main menu, and end screen.
  - Add nice looking animations.
  - Finished before due date.
- Secondary goals
  - Include puzzle like elements to get parts.
  - Add sound effects and music.
  - Add other game modes.
- Tertiary goals
  - Be able to randomize the levels.
  - Publish on the app stores.
#### 2.3. Operating environment
Our goal is to be able to put it on mobile Devices.
#### 2.4. Constraints
- We are a smaller team, so our game can't be too large. 
- Time is our biggest constraint, because we have to have this completed by the end of the Fall 2020 semester.
#### 2.5. User documentation

#### 2.6. Assumptions and dependencies
Assumptions
- We assume that our users will have an android device.
-We assume that we will be able to implement all the features in time.
Dependencies
- We will depend on Coco-2dx as our game engine.
- We will depend on the whole team staying on task, and doing their part.
## Section 3:

### 3. System Features

Music
Animation

#### 3.1. Functional requirement 1
Player will be able to control the character.
##### 3.1.1. Description and priority
The player will be able to control the character like moving around the level, and interacting with the environment. This will be a high priority.
##### 3.1.2. Stimulus and response
The player will use swipe gestures or maybe like a virtual joystick/ buttons to control the Character, in response the character could move, jump, duck, grab, throw, etc.
##### 3.1.3. Functional requirements
We will need to capture user input inorder to move the character in response.

#### 3.2. Functional requirement 2
There will be different levels that the player can progress through.
##### 3.2.1. Description and priority
There will be different levels, some more difficult than others, that the player can progress through.
##### 3.2.2. Stimulus and response
The level will have puzzle elements, and the player will be able to onto objects, or avoid other objects within the level. The goal will be to collect a key or a part to fix the alien's spaceship.
##### 3.2.3. Functional requirements
We will have to have art assests for the environment, be able to decide which objects hurt the player, and which objects the player can stand on or pass through.

## Section 4:
### 4. Nonfunctional Requirements
#### 4.1 Nonfunctional Requirement 1
Music/sound effects
##### 4.1.1 Description
Music will be playing throughout the game. The music can change with each level. Sound effect can also be used when the character gets hurt or when they finish the level.

#### 4.2 Nonfunctional Requirement 2
Game Animations
##### 4.2.1 Description
The environment and the character will have animation to give a more polished and finished feel to the game.

## Appendix A: Class Diagram:
![Class Diagram](https://github.com/maxwell7774/SoftwareEngineeringGroupProject/blob/master/Class_Diagram.png)
## Appendix B: One other diagram:
