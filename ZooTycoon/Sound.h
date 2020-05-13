#pragma once
#include <SFML/Audio.hpp>
class Sound
{
public:
	Sound(sf::SoundBuffer * buffer);
	~Sound();
	Sound();
	//play the sound 
	virtual void playSound();
	void stop();
	void pause();
	void loop();
protected:
	//return if is play sound
	bool isPlaying();

private:

	bool m_isPlaying = false;
	std::unique_ptr<sf::Sound> m_sound = std::make_unique<sf::Sound>();
};

