import tensorflow as tf


model = tf.keras.models.Sequential()

model.add(tf.keras.layers.Input(shape=(16,)))
model.add(tf.keras.layers.Dense(8, activation='sigmoid'))
model.add(tf.keras.layers.Dense(8, activation='sigmoid'))
model.add(tf.keras.layers.Dense(4, activation='sigmoid'))
model.add(tf.keras.layers.Dense(2, activation='sigmoid'))

model.compile()

model.save('neuro')
