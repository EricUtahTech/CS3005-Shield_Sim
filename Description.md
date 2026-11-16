This is a simulation of an energy shield:
1) Shield depletion based off shell-type fired and range (up to 100ft), max shield charge:100

2) Manual crank recharge that charges based on number of cranks, 1 crank is 7-12% randomly (like one of those crank flashlights)

3) A shot-blaster with 3 types of ammunition that will be loaded into a tube magazine with a maximum of m_capacity, default is 5 (uses a stack, just like all magazines, FILO) cannot fire if overheated and must be cooled to fire (cooled by 35-70)
Disclaimer: Not intended to model real life, this is made-up logic
- Slug (High damage at extremely close range, minimal damage dropoff over range, [linear scaling: 100<=25ft, 25>75ft as an example]
- Large Low-Density Bearings (lb) (High damage at close, but exponentially decreases effectiveness at range [100*(0.97)^distance, -3% per foot, 21.8 at 50ft, 4.8% at 100ft])
- Miniature High-Density Bearings (sb) (Medium Damage up close, but retains damage better at longer ranges [50*(0.9909)^distance, -0.91% per foot, 31.6 at 50ft, 20 at 100ft])