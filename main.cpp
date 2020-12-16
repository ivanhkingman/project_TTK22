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

// This program creates an example planDB with a pre-defined bottomUpSearch maneuver
// The plan specification is then sent locally on a port specified by the second input argument

int main(int argc, char** argv) {

    int portNumber = std::stoi(std::string(argv[1]));

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

    // BottomUpSearch
    BottomUpSearch bottomUpSearch;
    bottomUpSearch.timeout = 10000;
    bottomUpSearch.lat = 0.7188016469344056;
    bottomUpSearch.lon = -0.15194250254286037;
    bottomUpSearch.z = 3;
    bottomUpSearch.z_units = 1;
    bottomUpSearch.speed = 1000;
    bottomUpSearch.speed_units = 1;
    bottomUpSearch.desired_pitch = 1.57;
    bottomUpSearch.surface_threshold = 0.2;
    bottomUpSearch.pitch_threshold = 0.5;
    bottomUpSearch.burst_rpm = 1000;
    bottomUpSearch.thrust_duration = 2;
    
    bottomUpSearch.custom = "";

    // Set Entity Parameters
    SetEntityParameters setEntityParameters;
    setEntityParameters.name = "LBL";
    EntityParameter entityParameter;
    entityParameter.name = "Active";
    entityParameter.value = "false";
    MessageList<EntityParameter> parameters;
    parameters.push_back(entityParameter);
    setEntityParameters.params = parameters;

    // Add maneuver to plan specification
    InlineMessage<Maneuver> data;
    data.set(bottomUpSearch);
    planManeuver.data = data;
    MessageList<Message> startActions;
    startActions.push_back(setEntityParameters);
    planManeuver.start_actions = startActions;
    MessageList<PlanManeuver> maneuvers;
    maneuvers.push_back(planManeuver);
    planSpecification.maneuvers = maneuvers;

    // Add plan specification to a plan DB
    PlanDB planDB;
    planDB.type = 0;
    planDB.op = 0;
    planDB.plan_id = planSpecification.plan_id;
    planDB.arg.set(planSpecification);

    // Send the plan DB to a specified port
    int size = planDB.getSerializationSize();
    char buffer[size];
    Packet::serialize(&planDB, (uint8_t *) buffer, size);

    char localhost[] = "127.0.0.1";    
    DatagramSocket socket(portNumber, localhost, true, true);
    socket.sendTo(buffer, size, localhost);

    std::cout << "Sent bottomUpSearch as part of a plan DB to 127.0.0.1 on port "<< portNumber << std::endl;

    return 0;
}