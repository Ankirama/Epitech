package com.dot.epiandroid.api;

import android.content.Context;
import android.widget.Toast;

import com.dot.epiandroid.api.model.*;
import com.dot.epiandroid.api.model.Error;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.squareup.okhttp.ResponseBody;

import java.io.IOException;
import java.util.List;

import retrofit.Call;
import retrofit.GsonConverterFactory;
import retrofit.Retrofit;
import retrofit.http.DELETE;
import retrofit.http.Field;
import retrofit.http.FormUrlEncoded;
import retrofit.http.GET;
import retrofit.http.POST;
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
        @FormUrlEncoded
        @POST("/login")
        Call<Token> getToken(@Field("login") String login,
                             @Field("password") String password);

        @FormUrlEncoded
        @POST("/infos")
        Call<InformationStart> getInformationUser(@Field("token") String token);

        @GET("/user")
        Call<User> getUser(@Query("token") String token,
                           @Query("user") String user);

        @GET("/planning")
        Call<List<Planning>> getPlanning(@Query("token") String token,
                                         @Query("start") String start,
                                         @Query("end") String end);

        @GET("/messages")
        Call<List<Message>> getMessages(@Query("token") String token);

        @GET("/modules")
        Call<UserModule> getUserModule(@Query("token") String token);

        @GET("/module")
        Call<Module> getModule(@Query("token") String token,
                               @Query("scolaryear") String scolaryear,
                               @Query("codemodule") String codemodule,
                               @Query("codeinstance") String codeinstance);

        @GET("/allmodules")
        Call<Modules> getAllModules(@Query("token") String token,
                                    @Query("scolaryear") String scolar,
                                    @Query("location") String location,
                                    @Query("course") String course);

        @FormUrlEncoded
        @POST("/module")
        Call<SimpleUser> subscribeModule(@Field("token") String token,
                                         @Field("scolaryear") String scolaryear,
                                         @Field("codemodule") String codemodule,
                                         @Field("codeinstance") String codeinstance);

        @DELETE("/module")
        Call<SimpleUser> unsubscribeModule(@Query("token") String token,
                                           @Query("scolaryear") String scolaryear,
                                           @Query("codemodule") String codemodule,
                                           @Query("codeinstance") String codeinstance);

        @FormUrlEncoded
        @POST("/token")
        Call<String> validateToken(@Field("token") String token,
                                   @Field("scolaryear") String scolaryear,
                                   @Field("codemodule") String codemodule,
                                   @Field("codeinstance") String codeinstance,
                                   @Field("codeacti") String codeacti,
                                   @Field("codeevent") String codeevent,
                                   @Field("tokenvalidationcode") String code);

        @FormUrlEncoded
        @POST("/event")
        Call<Planning> subscribeEvent(@Field("token") String token,
                                      @Field("scolaryear") String scolaryaer,
                                      @Field("codemodule") String codemodule,
                                      @Field("codeinstance") String codeinstance,
                                      @Field("codeacti") String codeacti,
                                      @Field("codeevent") String codeevent);

        @DELETE("/event")
        Call<Planning> unsubscribeEvent(@Query("token") String token,
                                        @Query("scolaryear") String scolaryaer,
                                        @Query("codemodule") String codemodule,
                                        @Query("codeinstance") String codeinstance,
                                        @Query("codeacti") String codeacti,
                                        @Query("codeevent") String codeevent);

        @GET("/photo")
        Call<Picture> getPicture(@Query("token") String token,
                                 @Query("login") String login);

        @GET("/projects")
        Call<List<UserProject>> getProject(@Query("token") String token);

        @GET("/marks")
        Call<UserMark> getMark(@Query("token") String token);

        @GET("/trombi")
        Call<Trombi> getTrombi(@Query("token") String token,
                               @Query("year") String year,
                               @Query("location") String location,
                               @Query("course") String course,
                               @Query("promo") String promo,
                               @Query("offset") String offset );

        @FormUrlEncoded
        @POST("/project")
        Call<UserProjectResponse> subscribeProject(@Field("token") String token,
                                                   @Field("scolaryear") String scolaryear,
                                                   @Field("codemodule") String codemodule,
                                                   @Field("codeinstance") String codeinstance,
                                                   @Field("codeacti") String codeacti);

        @DELETE("/project")
        Call<UserProject> unsubscribeProject(@Query("token") String token,
                                             @Query("scolaryear") String scolaryear,
                                             @Query("codemodule") String codemodule,
                                             @Query("codeinstance") String codeinstance,
                                             @Query("codeacti") String codeacti);

        @GET("/project/files")
        Call<List<ProjectFile>> getFileProject(@Query("token") String token,
                                          @Query("scolaryear") String scolaryaer,
                                          @Query("codemodule") String codemodule,
                                          @Query("codeinstance") String codeinstance,
                                          @Query("codeacti") String codeacti);
    }
}
