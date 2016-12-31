#ifndef PCSTATUS_H
#define PCSTATUS_H

#include "commands.h"

/**
 * @brief The PCStatus class - This is a subclass of the Command class. This class accesses
 * task manager information to retrieve data such as CPU time and mem usage about each
 * running process
 */
class PCStatus: public Commands
{
    Q_OBJECT

public:

    /**
     * @brief PCStatus::PCStatus - The constructor for the PCStatus class. It
     * connects the necessary signals and slots, setups up the QProcess and assigns the commandID
     *
     * @param id - An int value to be assigned to this instance of the command class. For
     * error handling or notifications through signals, this value should be unique throughout
     * the runtime
     */
      PCStatus(int id);

      /**
       * @brief PCStatus::start - This method gets all the information regarding the running
       * processes on the system. It does this by initiating the command in another process
       * and notifies the user when the data is ready through the signal taskInfoReady
       *
       * @param args - This method takes no parameter. Any supplied parameter will be ignored
       *
       * @return - a boolean indicating whether the command has/is being executed
       */
      bool start(QStringList *args); //The method to start the execution of the PC status command

protected slots:

      /**
       * @brief PCStatus::taskInfo - This slot is invoked when the task information is available. It
       * extracts the needed data from it and passes it to the callee through the signal taskInfoReady
       */
      void taskInfo();

signals:
      /**
       * @brief taskInfoReady - This signal is emitted when the task manager data is available for use
       *
       * @param id - the instance of pcstatus that is emitting the signal
       *
       * @param data - A QStringList of the task manager data where each row represents specific data
       * about a process. Every 6th or 7th index represents a new process and its info
       */
      void taskInfoReady(int id, QStringList data);
};

#endif // PCSTATUS_H
