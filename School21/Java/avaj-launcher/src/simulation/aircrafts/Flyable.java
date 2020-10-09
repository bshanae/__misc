package simulation.aircrafts;

import simulation.towers.WeatherTower;

public interface    Flyable
{
    void            updateConditions();
    void            registerTower(WeatherTower weatherTower);
}