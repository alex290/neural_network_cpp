import tensorflow as tf
import pandas as pd
import numpy as np

data_input = pd.read_csv("input.csv")
data_output = pd.read_csv("out.csv")

input_tren = np.array(data_input.values)
otput_tren = np.array(data_output.values)

model = tf.keras.models.load_model('neuro')

sgd = tf.keras.optimizers.SGD(learning_rate=0.3, momentum=0.0, nesterov=False)

model.compile(loss='mean_squared_error', optimizer=sgd)

model.save('neuro')

loss_last = 1

while loss_last > 0.001:

    history = model.fit(input_tren, otput_tren, epochs=1000)

    model.save('neuro')

    loss_hyst = np.array(history.history['loss'])

    loss_last = loss_hyst[loss_hyst.size - 1]

    print(loss_hyst[loss_hyst.size - 1])
