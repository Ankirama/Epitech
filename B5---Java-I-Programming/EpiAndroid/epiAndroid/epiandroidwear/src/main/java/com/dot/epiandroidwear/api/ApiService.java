package com.dot.epiandroidwear.api;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

import java.util.List;

import retrofit.Call;
import retrofit.GsonConverterFactory;
import retrofit.Retrofit;
import retrofit.http.GET;
import retrofit.http.Query;

/**
 * Created by doT on 05/01/2016.
 */
public class ApiService {
    public static final String URL_BASE = "http://epitech-api.herokuapp.com";
    private static ApiCall apiService;

    public static ApiCall getApiService() {
        if (apiService == null) {
            Gson gson = new GsonBuilder()
                    .setDateFormat("yyyy-MM-dd'T'HH:mm:ssZ")
                    .create();

            Retrofit retrofit = new Retrofit.Builder()
                    .baseUrl(URL_BASE)
                    .addConverterFactory(GsonConverterFactory.create(gson))
                    .build();

            apiService = retrofit.create(ApiCall.class);
        }
        return apiService;
    }

    public interface ApiCall {
        @GET("/messages")
        Call<List<Message>> getMessages(@Query("token") String token);
    }
}
