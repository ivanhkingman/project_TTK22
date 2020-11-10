#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Base/Packet.hpp>
#include <IMC/Base/Factory.cpp>
#include "UDP/DatagramSocket.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#define LAUVXPLORE1 (30)
using namespace IMC;

// This program creates an example planSpecification with a maneuver, specified by the input arguments.
// The plan specification is then sent locally on a port specified by the second input argument

int main(int argc, char** argv ) {

    std::string maneuverString = std::string(argv[2]);
    int portNumber = std::stoi(std::string(argv[3]));

    // Plan specification                                      
    PlanSpecification planSpecification;
    planSpecification.setTimeStamp(1.5628304294681385E9);                    
    planSpecification.setDestination(30);
    planSpecification.setSource(16652);
    planSpecification.setSourceEntity(44);
    planSpecification.setDestinationEntity(255);
    planSpecification.plan_id = "test_plan";
    planSpecification.start_man_id = "1";                       

    // Plan Maneuver
    PlanManeuver planManeuver;
    planManeuver.maneuver_id = "1";

    // Loiter
    Loiter loiter;
    loiter.timeout = 10000;
    loiter.lat = 0.7188016469344056;
    loiter.lon = -0.15194250254286037;
    loiter.z = 3;
    loiter.z_units = 1;
    loiter.duration = 300;
    loiter.speed = 1000;
    loiter.speed_units = 1;
    loiter.type = 1;
    loiter.radius = 20;
    loiter.length = 1;
    loiter.bearing = 0;
    loiter.direction = 1;
    loiter.custom = "";

    // BottomUpSearch
    BottomUpSearch bottomUpSearch;
    bottomUpSearch.timeout = 10000;
    bottomUpSearch.lat = 0.7188016469344056;
    bottomUpSearch.lon = -0.15194250254286037;
    bottomUpSearch.z = 3;
    bottomUpSearch.z_units = 1;
    bottomUpSearch.speed = 1000;
    bottomUpSearch.speed_units = 1;
    bottomUpSearch.pitch_thresh = 1;
    bottomUpSearch.thrust_duration = 2;
    bottomUpSearch.custom = "";

    // BottomUpSearch
    Goto goTo;
    goTo.timeout = 10000;
    goTo.lat = 0.7188016469344056;
    goTo.lon = -0.15194250254286037;
    goTo.z = 3;
    goTo.z_units = 1;
    goTo.speed = 1000;
    goTo.speed_units = 1;
    goTo.custom = "";

    // Abort message
    Abort abort;
    abort.setDestination(30);

    // Set Entity Parameters
    SetEntityParameters setEntityParameters;
    setEntityParameters.name = "LBL";
    
    // Entity Parameter
    EntityParameter entityParameter;
    entityParameter.name = "Active";
    entityParameter.value = "false";
    
    //! Inline message-fields
    MessageList<EntityParameter> parameters;
    parameters.push_back(entityParameter);
    setEntityParameters.params = parameters;

    InlineMessage<Maneuver> data;
    data.set(loiter);
    if (maneuverString == "goTo" || maneuverString == "goto") {
        data.set(goTo);
    }
    if (maneuverString == "bottomUpSearch") {
        data.set(bottomUpSearch);
    }
    if (maneuverString == "loiter") {
        data.set(loiter);
    }
    planManeuver.data = data;

    MessageList<Message> startActions;
    startActions.push_back(setEntityParameters);
    planManeuver.start_actions = startActions;

    MessageList<PlanManeuver> maneuvers;
    maneuvers.push_back(planManeuver);
    planSpecification.maneuvers = maneuvers;

    // Message sending
    int size = planSpecification.getSerializationSize();
    char buffer[size];
    Packet::serialize(&planSpecification, (uint8_t *) buffer, size);

    char localhost[] = "127.0.0.1";    
    DatagramSocket socket(6001, localhost, true, true);
    socket.sendTo(buffer, size, localhost);

    std::cout << "Sent " << maneuverString << " as part of a plan specification to 127.0.0.1 on port "<< portNumber << std::endl;

    return 0;
}