/*
 * Created by Tucker Haydon on 8/8/17.
 */

#pragma once

/*
 * IMessage is an interface that should be implemented by all messages being passed between components in the system.
 * Messages are required to specify their destination so the CommunicationBus can pass the message along.
 */
class IMessage
{
public:
    /**
     * Pure virtual destructor allowing polymorphic delete.
     */
    virtual ~IMessage() = 0;

    /**
     * Returns a string identifier of the destination component.
     * @return String identified of destination component.
     */
    std::string getDestination() {return this->destination;}

    // Forbid copying
    IMessage(IMessage const &) = delete;
    IMessage & operator=(IMessage const &) = delete;

protected:
    /**
     * Constructor.
     * @param destination Unique string that identifies the component the message is destined for.
     */
    IMessage(std::string destination) {this->destination = destination;}

    /**
     * String identifier of destination component.
     */
    std::string destination;
};
