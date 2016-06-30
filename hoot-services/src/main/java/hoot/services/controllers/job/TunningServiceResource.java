/*
 * This file is part of Hootenanny.
 *
 * Hootenanny is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * The following copyright notices are generated automatically. If you
 * have a new notice to add, please use the format:
 * " * @copyright Copyright ..."
 * This will properly maintain the copyright information. DigitalGlobe
 * copyrights will be updated automatically.
 *
 * @copyright Copyright (C) 2015, 2016 DigitalGlobe (http://www.digitalglobe.com/)
 */
package hoot.services.controllers.job;

import java.util.UUID;

import javax.ws.rs.Consumes;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.WebApplicationException;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.Response.Status;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import hoot.services.job.JobExecutioner;


@Path("/tunning")
public class TunningServiceResource {
    private static final Logger logger = LoggerFactory.getLogger(TunningServiceResource.class);

    public TunningServiceResource() {
    }

    @POST
    @Path("/execute")
    @Consumes(MediaType.TEXT_PLAIN)
    @Produces(MediaType.TEXT_PLAIN)
    public Response process(String params) {
        try {
            JSONParser pars = new JSONParser();
            JSONObject oParams = (JSONObject) pars.parse(params);
            String input = oParams.get("INPUT").toString();
            String inputtype = oParams.get("INPUT_TYPE").toString();

            JSONObject command = new JSONObject();
            command.put("input", input);
            command.put("inputtype", inputtype);
            command.put("execImpl", "TunningService");

            String jobId = UUID.randomUUID().toString();

            (new JobExecutioner(jobId, command)).start();

            JSONObject res = new JSONObject();
            res.put("jobId", jobId);

            return Response.ok(res.toJSONString(), MediaType.APPLICATION_JSON).build();
        }
        catch (Exception e) {
            String message = "Tuning Service error: " + e.getMessage();
            logger.error(message, e);
            throw new WebApplicationException(e, Response.status(Status.INTERNAL_SERVER_ERROR).entity(message).build());
        }
    }
}
