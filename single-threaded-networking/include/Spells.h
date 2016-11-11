#ifndef SPELLS_H
#define SPELLS_H

#include <unordered_map>

#include "SpellInterface.h"
#include "Npc.h"
#include "Room.h"
#include "Object.h"
#include "Player.h"
#include "Context.h"
namespace Spells{

	class DefenseSpell : public Spell
	{
	private:
		int duration;
		int mana;
		int minLevel;
		std::string name;
		std::vector<string> effect;
		std::vector<string> dammsg;
		std::vector<string> hitChar;
		std::vector<string> hitRoom;
		std::vector<string> hitVict;
		std::vector<string> wearOff;
		networking::Connection connection;

	public:
		//Constructor
		DefenseSpell()
		DefenseSpell(int duration_, int mana_, int minLevel, std::string& name_);
		
		std::string getName()const;
		//
		std::vector<string> getEffect()const;
		void setEffect(std::vector<string> effect_);

		//
		std::vector<string> getDammsg()const;
		void setDammsg(std::vector<string> dammsg_);

		//
		std::vector<string> getHitChar()const;
		void setHitChar(std::vector<string> hitChar);

		//
		std::vector<string> getHitRoom()const;
		void setHitRoom(std::vector<string> hitRoom);

		//
		std::vector<string> getHitVict()const;
		void setHitVict(std::vector<string> hitvict);

		//
		std::vector<string> getWearoff()const;
		void setWearoff(std::vector<string> wearoff);

		DefenseSpell(networking::Connection_,);
		std::string execute(Context& context);
		networking::Connection getConnection() const;



		
	};

	class OffenseSpell : public Spell {
	private:
		int duration;
		int mana;
		int minlevel;

		std::string name;

		std::vector<string>  dammsg;
		std::vector<string>  missromm;
		std::vector<string>  effect; 
		std::vector<string>  hitchar;
		std::vector<string>  hitroom;
		std::vector<string>  hitvict;
		std::vector<string>  immchar;
		std::vector<string>  wearoff;

		networking::Connection connection;

	public:
		//Constructor
		OffenseSpell()
		OffenseSpell(int new_duration, int new_mana, int new_minLevel, std::string& new_name);
		
		std::string getName()const;
		//
		std::vector<std::string> getEffect()const;
		void setEffect(std::vector<std::string>& new_effect);

		//
		std::vector<std::string> getDammsg()const;
		void setDammsg(std::vector<std::string>& new_dammsg);

		//
		std::vector<std::string> getHitChar()const;
		void setHitChar(std::vector<std::string>& new_hitChar);

		//
		std::vector<std::string> getHitRoom()const;
		void setHitRoom(std::vector<std::string>& new_hitRoom);

		//
		std::vector<std::string> getHitVict()const;
		void setHitVict(std::vector<std::string>& new_hitVict);

		//
		std::vector<std::string> getImmchar()const;
		void setImmchar(std::vector<std::string>& new_immChar);

		//
		std::vector<std::string> getWearoff()const;
		void setWearoff(std::vector<std::string>& new_wearOff);

		DefenseSpell(networking::Connection_,);
		std::string execute(Context& context);
		networking::Connection getConnection() const;

	};

	class ObjectSpell : public Spell {
	private:
		int duration;
		int mana;
		int minlevel;

		std::string name;

		std::vector<string>  dammsg;
		std::vector<string>  missromm;
		std::vector<string>  effect; 
		std::vector<string>  hitchar;
		std::vector<string>  hitroom;
		std::vector<string>  hitvict;

		networking::Connection connection;

	public:
		//Constructor
		ObjectSpell()
		ObjectSpell(int new_duration, int new_mana, int new_minLevel, std::string& new_name);
		
		std::string getName()const;
		//
		std::vector<std::string> getEffect()const;
		void setEffect(std::vector<std::string>& new_effect);

		//
		std::vector<std::string> getDammsg()const;
		void setDammsg(std::vector<std::string>& new_dammsg);

		//
		std::vector<std::string> getHitChar()const;
		void setHitChar(std::vector<std::string>& new_hitChar);

		//
		std::vector<std::string> getHitRoom()const;
		void setHitRoom(std::vector<std::string>& new_hitRoom);

		//
		std::vector<std::string> getHitVict()const;
		void setHitVict(std::vector<std::string>& new_hitVict);

		DefenseSpell(networking::Connection_,);
		std::string execute(Context& context);
		networking::Connection getConnection() const;

	};
}


#endif
