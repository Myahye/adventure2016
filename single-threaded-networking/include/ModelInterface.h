#ifndef modelinterface_h
#define modelinterface_h

#include "Server.h"
#include "Model.h"
#include <chrono>


class ModelInterface {

private:
	Model model{"../data/shire.yml"};
	std::chrono::time_point<std::chrono::system_clock> combatPrevious, nonCombatPrevious, combatCurrent, nonCombatCurrent;
	std::chrono::duration<double> combatElapsed, nonCombatElapsed, combatLag, nonCombatLag, MS_PER_COMBAT_UPDATE, MS_PER_NONCOMBAT_UPDATE;

	//place holders till commands are in place.
	std::deque<networking::Message> mclientMessages;
	std::vector<networking::Connection> mclients;
public:
  ModelInterface();

	void buildCommands(const std::deque<networking::Message>& clientMessages, std::vector<networking::Connection>& clients);

  std::deque<networking::Message> parseCommands(const std::deque<networking::Message>& clientMessages,  std::vector<networking::Connection>& clients);
	std::deque<networking::Message> updateGame(const std::deque<networking::Message>& clientMessages,  std::vector<networking::Connection>& clients);
	std::deque<networking::Message> dequeConcatenate(const std::deque<networking::Message> left, const std::deque<networking::Message> right);
	bool tickIsUpForCombatTimer();
	bool tickIsUpForNonCombatTimer();

  int createPlayer(const std::string& username, const std::string& password);
  std::vector<std::tuple<int,std::string,std::string>> getPlayerCredentialsVector() const;
  std::string getCurrentRoomDescription(const int& playerId);
};

#endif /* modelinterface_h */
